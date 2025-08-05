## PyNDS
A Python interface for [NooDS](https://github.com/Hydr8gon/NooDS), a Nintendo DS emulator. Intended for reinforcement learning and bots.

Inspired by [PyBoy](https://github.com/Baekalfen/PyBoy).

### Example
```py
import pynds
rom_path = "path/to/rom"

nds = pynds(rom_path)
nds.tick() # Runs the emulator until we get a frame
frame_top, frame_bottom = nds.get_frame() # Get the generated frame
```

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

**Disclaimer:** The project is still in its initial stages; expect a lot of bugs. The API is subject to change.
