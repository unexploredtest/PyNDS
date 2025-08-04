
class Memory:
    def __init__(self, nds):
        self._nds = nds

    # Read memory methods
    def read_ram_u8(self, address: int) -> int:
        return self._nds.read_ram_u8(address)

    def read_ram_u16(self, address: int) -> int:
        return self._nds.read_ram_u16(address)

    def read_ram_u32(self, address: int) -> int:
        return self._nds.read_ram_u32(address)

    def read_ram_u64(self, address: int) -> int:
        return self._nds.read_ram_u64(address)

    def read_ram_i8(self, address: int) -> int:
        return self._nds.read_ram_i8(address)

    def read_ram_i16(self, address: int) -> int:
        return self._nds.read_ram_i16(address)

    def read_ram_i32(self, address: int) -> int:
        return self._nds.read_ram_i32(address)

    def read_ram_i64(self, address: int) -> int:
        return self._nds.read_ram_i64(address)

    def read_ram_f32(self, address: int) -> float:
        return self._nds.read_ram_f32(address)

    def read_ram_f64(self, address: int) -> float:
        return self._nds.read_ram_f64(address)

    def read_map(self, start_address: int, end_address: int) -> list:
        return self._nds.read_map(start_address, end_address)

    # Write memory methods
    def write_ram_u8(self, address: int, value: int) -> None:
        self._nds.write_ram_u8(address, value)

    def write_ram_u16(self, address: int, value: int) -> None:
        self._nds.write_ram_u16(address, value)

    def write_ram_u32(self, address: int, value: int) -> None:
        self._nds.write_ram_u32(address, value)

    def write_ram_u64(self, address: int, value: int) -> None:
        self._nds.write_ram_u64(address, value)

    def write_ram_i8(self, address: int, value: int) -> None:
        self._nds.write_ram_i8(address, value)

    def write_ram_i16(self, address: int, value: int) -> None:
        self._nds.write_ram_i16(address, value)

    def write_ram_i32(self, address: int, value: int) -> None:
        self._nds.write_ram_i32(address, value)

    def write_ram_i64(self, address: int, value: int) -> None:
        self._nds.write_ram_i64(address, value)

    def write_ram_f32(self, address: int, value: float) -> None:
        self._nds.write_ram_f32(address, value)

    def write_ram_f64(self, address: int, value: float) -> None:
        self._nds.write_ram_f64(address, value)

    def write_map(self, start_address: int, data: list) -> None:
        self._nds.write_map(start_address, data)
