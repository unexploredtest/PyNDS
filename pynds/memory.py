class Memory:
    def __init__(self, nds):
        self._nds = nds

    # Read memory methods
    def read_ram_u8(self, arm7: bool, address: int, tcm: bool = False) -> int:
        return self._nds.read_ram_u8(arm7, address, tcm)

    def read_ram_u16(self, arm7: bool, address: int, tcm: bool = False) -> int:
        return self._nds.read_ram_u16(arm7, address, tcm)

    def read_ram_u32(self, arm7: bool, address: int, tcm: bool = False) -> int:
        return self._nds.read_ram_u32(arm7, address, tcm)

    # def read_ram_u64(self, arm7: bool, address: int, tcm: bool = False) -> int:
    #     return self._nds.read_ram_u64(arm7, address, tcm)

    def read_ram_i8(self, arm7: bool, address: int, tcm: bool = False) -> int:
        return self._nds.read_ram_i8(arm7, address, tcm)

    def read_ram_i16(self, arm7: bool, address: int, tcm: bool = False) -> int:
        return self._nds.read_ram_i16(arm7, address, tcm)

    def read_ram_i32(self, arm7: bool, address: int, tcm: bool = False) -> int:
        return self._nds.read_ram_i32(arm7, address, tcm)

    # def read_ram_i64(self, arm7: bool, address: int, tcm: bool = False) -> int:
    #     return self._nds.read_ram_i64(arm7, address, tcm)

    def read_ram_f32(self, arm7: bool, address: int, tcm: bool = False) -> float:
        return self._nds.read_ram_f32(arm7, address, tcm)

    # def read_ram_f64(self, arm7: bool, address: int, tcm: bool = False) -> float:
    #     return self._nds.read_ram_f64(arm7, address, tcm)

    def read_map(self, start_address: int, end_address: int) -> list:
        return self._nds.read_map(start_address, end_address)

    # Write memory methods
    def write_ram_u8(self, arm7: bool, address: int, value: int, tcm: bool = False) -> None:
        self._nds.write_ram_u8(arm7, address, value, tcm)

    def write_ram_u16(self, arm7: bool, address: int, value: int, tcm: bool = False) -> None:
        self._nds.write_ram_u16(arm7, address, value, tcm)

    def write_ram_u32(self, arm7: bool, address: int, value: int, tcm: bool = False) -> None:
        self._nds.write_ram_u32(arm7, address, value, tcm)

    # def write_ram_u64(self, arm7: bool, address: int, value: int, tcm: bool = False) -> None:
    #     self._nds.write_ram_u64(arm7, address, value, tcm)

    def write_ram_i8(self, arm7: bool, address: int, value: int, tcm: bool = False) -> None:
        self._nds.write_ram_i8(arm7, address, value, tcm)

    def write_ram_i16(self, arm7: bool, address: int, value: int, tcm: bool = False) -> None:
        self._nds.write_ram_i16(arm7, address, value, tcm)

    def write_ram_i32(self, arm7: bool, address: int, value: int, tcm: bool = False) -> None:
        self._nds.write_ram_i32(arm7, address, value, tcm)

    # def write_ram_i64(self, arm7: bool, address: int, value: int, tcm: bool = False) -> None:
    #     self._nds.write_ram_i64(arm7, address, value, tcm)

    def write_ram_f32(self, arm7: bool, address: int, value: float, tcm: bool = False) -> None:
        self._nds.write_ram_f32(arm7, address, value, tcm)

    # def write_ram_f64(self, arm7: bool, address: int, value: float, tcm: bool = False) -> None:
    #     self._nds.write_ram_f64(arm7, address, value, tcm)

    def write_map(self, start_address: int, size: int, data: list) -> None:
        self._nds.write_map(start_address, size, data)
