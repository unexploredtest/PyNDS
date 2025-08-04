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


class Button:
    def __init__(self, nds):
        self._nds = nds

    def set_touch(self, x: int, y: int) -> None:
        self._nds.set_touch_input(x, y)

    def clear_touch(self) -> None:
        self._nds.clear_touch_input()

    def touch(self) -> None:
        self._nds.touch_input()

    def release_touch(self) -> None:
        self._nds.release_touch_input()

    def press_key(self, key: str) -> None:
        self._nds.press_key(KEY_MAP[key])

    def release_key(self, key: str) -> None:
        self._nds.release_key(KEY_MAP[key])
