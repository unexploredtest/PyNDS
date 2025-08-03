from typing import Union, Tuple, List
import numpy as np

import cnds
from .memory import Memory
from .button import Button


class PyNDS:
    def __init__(self, path: str, auto_detect: bool = True, is_gba: bool = False) -> None:
        if(auto_detect):
            is_gba = path.endswith(".gba")

        self.is_gba = is_gba
        self._nds = cnds.Nds(path, is_gba)
        self.button = Button(self._nds)
        self.memory = Memory(self._nds)

    def tick(self, count: int = 1) -> None:
        for i in range(count):
            self._nds.run_until_frame()
            self._nds.get_frame()

    def get_frame(self) -> Union[Tuple[np.ndarray, np.ndarray], np.ndarray]:
        if(self.is_gba):
            width = 240
            height = 160
            frame = self._nds.get_gba_frame()
            return self._convert_img_to_np(frame, width, height)
        else:
            width = 256
            height = 192
            top_frame = self._nds.get_top_nds_frame()
            bot_frame = self._nds.get_bot_nds_frame()
            return (self._convert_img_to_np(top_frame, width, height),
                self._convert_img_to_np(bot_frame, width, height))

    def save_state_to_file(self, path: str) -> None:
        self._nds.save_state(path)

    def load_state_from_file(self, path: str) -> None:
        self._nds.load_state(path)

    @staticmethod
    def _convert_img_to_np(frame: List[int], width: int, height: int) -> np.ndarray:
        rgb_array = np.array(frame, dtype=np.uint32)
        
        r = (rgb_array) & 0xFF
        g = (rgb_array >> 8) & 0xFF
        b = (rgb_array >> 16) & 0xFF
        a = (rgb_array >> 24) & 0xFF

        image_array = np.stack((r, g, b, a), axis=-1)
        # image_array = np.stack((r, g, b), axis=-1)
        image_array = image_array.reshape((height, width, 4))
        image_array = image_array.astype(np.uint8)

        return image_array
