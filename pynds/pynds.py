from typing import Union, Tuple, List
import numpy as np

import cnds
from .memory import Memory
from .button import Button
from .config import config


class PyNDS:
    def __init__(self, path: str, auto_detect: bool = True, is_gba: bool = False) -> None:
        if (auto_detect):
            is_gba = path.endswith(".gba")

        self.is_gba = is_gba
        self._nds = cnds.Nds(path, is_gba)
        self.button = Button(self._nds)
        self.memory = Memory(self._nds)

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

    def save_state_to_file(self, path: str) -> None:
        self._nds.save_state(path)

    def load_state_from_file(self, path: str) -> None:
        self._nds.load_state(path)
