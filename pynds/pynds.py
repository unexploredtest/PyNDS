import os
from typing import Union, Tuple
import numpy as np

import cnds
from .memory import Memory
from .button import Button
from .window import Window
from .config import config


class PyNDS:
    def __init__(self, path: str, auto_detect: bool = True, is_gba: bool = False) -> None:
        if (auto_detect):
            is_gba = path.endswith(".gba")

        self.is_gba = is_gba

        self.check_file_exist(path)
        self._nds = cnds.Nds(path, is_gba)

        self.button = Button(self._nds)
        self.memory = Memory(self._nds)
        self.window = Window(self)

    def get_is_gba(self) -> bool:
        return self.is_gba

    def tick(self, count: int = 1) -> None:
        for i in range(count):
            self._nds.run_until_frame()
            self._nds.get_frame()

    def get_frame(self) -> Union[Tuple[np.ndarray, np.ndarray], np.ndarray]:
        if (self.is_gba):
            frame = self._nds.get_gba_frame()
            return frame
        else:
            top_frame = self._nds.get_top_nds_frame()
            bot_frame = self._nds.get_bot_nds_frame()
            return (top_frame, bot_frame)

    def get_frame_shape(self) -> Tuple[int, int]:
        NDS = (192, 256)
        GBA = (160, 240)
        if (config.get_high_res_3d() or config.get_screen_filter() == 1):
            scale = 2
        else:
            scale = 1

        if (self.is_gba):
            return (GBA[0]*scale, GBA[1]*scale, 4)
        else:
            return (NDS[0]*scale, NDS[1]*scale, 4)

    def open_window(self, width: int = 800, height: int = 800) -> None:
        if (self.window.running):
            self.window.close()

        self.window.init(width, height)

    def close_window(self) -> None:
        self.window.close()

    def render(self) -> None:
        if (self.window.running):
            self.window.render()

    def save_state_to_file(self, path: str) -> None:
        self._nds.save_state(path)

    def load_state_from_file(self, path: str) -> None:
        self.check_file_exist(path)
        self._nds.load_state(path)

    def write_save_file(self, path: str) -> None:
        self._nds.save_game(path)

    @staticmethod
    def check_file_exist(path: str) -> None:
        if not os.path.isfile(path):
            raise FileNotFoundError(f"File '{path}' does not exist.")
