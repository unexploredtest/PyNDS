import os
import platform
import subprocess
import sys
from pprint import pprint
from setuptools import setup, Extension, find_packages
from setuptools.command.build_ext import build_ext
from pathlib import Path

c_module_name = 'cnds'

cmake_cmd_args = []
for f in sys.argv:
    if f.startswith('-D'):
        cmake_cmd_args.append(f)

for f in cmake_cmd_args:
    sys.argv.remove(f)

print(cmake_cmd_args)


def _get_env_variable(name, default='OFF'):
    if name not in os.environ.keys():
        return default
    return os.environ[name]


class CMakeExtension(Extension):
    def __init__(self, name, cmake_lists_dir='.', sources=[], **kwa):
        Extension.__init__(self, name, sources=sources, **kwa)
        self.cmake_lists_dir = os.path.abspath(cmake_lists_dir)


class CMakeBuild(build_ext):

    def build_extensions(self):
        try:
            out = subprocess.check_output(['cmake', '--version'])
        except OSError:
            raise RuntimeError('Cannot find CMake executable')

        for ext in self.extensions:

            extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
            cfg = 'Debug' if _get_env_variable('PYNDS_DEBUG') == 'ON' else 'Release'

            cmake_args = [
                '-DCMAKE_BUILD_TYPE=%s' % cfg,
                # Ask CMake to place the resulting library in the directory
                # containing the extension
                '-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_{}={}'.format(cfg.upper(), extdir),
                # Other intermediate static libraries are placed in a
                # temporary build directory instead
                '-DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_{}={}'.format(cfg.upper(), self.build_temp)
            ]

            if platform.system() == 'Windows':
                plat = ('x64' if platform.architecture()[0] == '64bit' else 'Win32')
                cmake_args += [
                    '-DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE',
                    '-DCMAKE_RUNTIME_OUTPUT_DIRECTORY_{}={}'.format(cfg.upper(), extdir),
                ]
                if self.compiler.compiler_type == 'msvc':
                    cmake_args += [
                        '-DCMAKE_GENERATOR_PLATFORM=%s' % plat,
                    ]
                else:
                    cmake_args += [
                        '-G', 'MinGW Makefiles',
                    ]

            cmake_args += cmake_cmd_args

            pprint(cmake_args)

            if not os.path.exists(self.build_temp):
                os.makedirs(self.build_temp)

            # Config and build the extension
            subprocess.check_call(['cmake', ext.cmake_lists_dir] + cmake_args,
                                cwd=self.build_temp)

            # Build with multiple jobs
            num_jobs = os.cpu_count() or 1
            subprocess.check_call(['cmake', '--build', '.', '--config', cfg, '--parallel', str(num_jobs)],
                                cwd=self.build_temp)


version = '0.1'

setup(name='pynds',
      packages=find_packages(),
      install_requires=['numpy'],
      version=version,
      description='Python bindings for NooDS',
      author='unexploredtest',
      author_email='unexploredtest@tutanota.com',
      url='https://github.com/unexploredtest/PyNDS',
      keywords=['noods', 'emulator', 'nintendo ds', 'gameboy advance', 'python', 'c++'],
      long_description=open('README.md').read(),
      long_description_content_type='text/markdown',
      ext_modules=[CMakeExtension(c_module_name)],
      cmdclass={'build_ext': CMakeBuild},
      zip_safe=False,
      classifiers=[
          "Programming Language :: Python :: 3",
          "Operating System :: MacOS",
          "Operating System :: Microsoft :: Windows",
          "Operating System :: POSIX :: Linux",
      ],
)