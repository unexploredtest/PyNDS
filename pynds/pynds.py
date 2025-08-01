from typing import Union, Tuple, List
import numpy as np

import cnds

KEY_MAP = {
    'a': 0,
    'b': 1,
    'select': 2,
    'start': 3,
    'right': 4,
    'left': 5,
    'up': 6,
    'down': 7,
    'r': 8,
    'l': 9,
    'x': 10,
    'y': 11
}

class PyNDS:
    def __init__(self, path: str, auto_detect: bool = True, is_gba: bool = False) -> None:
        if(auto_detect):
            is_gba = path.endswith(".gba")

        self.is_gba = is_gba
        self._nds = cnds.Nds(path, is_gba)

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

    def set_touch_input(self, x: int, y: int) -> None:
        self._nds.set_touch_input(x, y)

    def clear_touch_input(self) -> None:
        self._nds.clear_touch_input()

    def touch_input(self) -> None:
        self._nds.touch_input()

    def release_touch_input(self) -> None:
        self._nds.release_touch_input()

    def press_key(self, key: str) -> None:
        self._nds.press_key(KEY_MAP[key])

    def release_key(self, key: str) -> None:
        self._nds.release_key(KEY_MAP[key])

    @staticmethod
    def _convert_img_to_np(frame: List[int], width: int, height: int) -> np.ndarray:
        rgb_array = np.array(frame, dtype=np.uint32)
        
        r = (rgb_array) & 0xFF
        g = (rgb_array >> 8) & 0xFF
        b = (rgb_array >> 16) & 0xFF
        a = (rgb_array >> 24) & 0xFF

        image_array = np.stack((r, g, b, a), axis=-1)
        image_array = image_array.reshape((height, width, 4))

        return image_array
