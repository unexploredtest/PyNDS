## PyNDS
A python interface for NooDS, a Nintendo DS emulator.

Inspired from PyBoy.

### Example
```py
import pynds
rom_path = "path/to/rom"

nds = pynds(rom_path)
nds.tick() # Runs the emulator until we get a frame
frame_top, frame_bottom = nds.get_frame() # Get the generated frame
```

Disclaimer: The project is still in its initial stages, expect a lot of bugs. Changes to the API might occur.

### Install
```sh
pip install pynds
```

### Build
```sh
git clone https://github.com/unexploredtest/PyNDS.git
cd PyNDS
git submodule update --init --recursive
python setup.py install
```
