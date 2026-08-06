#include "nds.hpp"
#include <bit>


// Read memory methods
uint8_t Nds::readRamu8(bool arm7, uint32_t address, bool tcm) {
    return m_core->memory.read<uint8_t>(arm7, address, tcm);
}

uint16_t Nds::readRamu16(bool arm7, uint32_t address, bool tcm) {
    return m_core->memory.read<uint16_t>(arm7, address, tcm);
}

uint32_t Nds::readRamu32(bool arm7, uint32_t address, bool tcm) {
    return m_core->memory.read<uint32_t>(arm7, address, tcm);
}

// uint64_t Nds::readRamu64(bool arm7, uint32_t address, bool tcm) {
//     return m_core->memory.read<uint64_t>(arm7, address, tcm);
// }

int8_t Nds::readRami8(bool arm7, uint32_t address, bool tcm) {
    return std::bit_cast<int8_t>(m_core->memory.read<uint8_t>(arm7, address, tcm));
}

int16_t Nds::readRami16(bool arm7, uint32_t address, bool tcm) {
    return std::bit_cast<int16_t>(m_core->memory.read<uint16_t>(arm7, address, tcm));
}

int32_t Nds::readRami32(bool arm7, uint32_t address, bool tcm) {
    return std::bit_cast<int32_t>(m_core->memory.read<uint32_t>(arm7, address, tcm));
}

// int64_t Nds::readRami64(bool arm7, uint32_t address, bool tcm) {
//     return std::bit_cast<int64_t>(m_core->memory.read<uint64_t>(arm7, address, tcm));
// }

float Nds::readRamf32(bool arm7, uint32_t address, bool tcm) {
    return std::bit_cast<float>(m_core->memory.read<uint32_t>(arm7, address, tcm));
}

// double Nds::readRamf64(bool arm7, uint32_t address, bool tcm) {
//     return std::bit_cast<double>(m_core->memory.read<uint64_t>(arm7, address, tcm));
// }

std::vector<uint8_t> Nds::readMap(uint32_t sAddress, uint32_t eAddress) {
    uint32_t size = eAddress - sAddress + 1;
    std::vector<uint8_t> buffer(size);
    m_core->memory.readMap(sAddress, eAddress, buffer.data());
    return std::move(buffer);
}

// Write memory methods
void Nds::writeRamu8(bool arm7, uint32_t address, uint8_t value, bool tcm) {
    m_core->memory.write<uint8_t>(arm7, address, value, tcm);
}

void Nds::writeRamu16(bool arm7, uint32_t address, uint16_t value, bool tcm) {
    m_core->memory.write<uint16_t>(arm7, address, value, tcm);
}

void Nds::writeRamu32(bool arm7, uint32_t address, uint32_t value, bool tcm) {
    m_core->memory.write<uint32_t>(arm7, address, value, tcm);
}

// void Nds::writeRamu64(bool arm7, uint32_t address, uint64_t value, bool tcm) {
//     m_core->memory.write<uint64_t>(arm7, address, value, tcm);
// }

void Nds::writeRami8(bool arm7, uint32_t address, int8_t value, bool tcm) {
    m_core->memory.write<uint8_t>(arm7, address, std::bit_cast<uint8_t>(value), tcm);
}

void Nds::writeRami16(bool arm7, uint32_t address, int16_t value, bool tcm) {
    m_core->memory.write<uint16_t>(arm7, address, std::bit_cast<uint16_t>(value), tcm);
}

void Nds::writeRami32(bool arm7, uint32_t address, int32_t value, bool tcm) {
    m_core->memory.write<uint32_t>(arm7, address, std::bit_cast<uint32_t>(value), tcm);
}

// void Nds::writeRami64(bool arm7, uint32_t address, int64_t value, bool tcm) {
//     m_core->memory.write<uint64_t>(arm7, address, std::bit_cast<uint64_t>(value), tcm);
// }

void Nds::writeRamf32(bool arm7, uint32_t address, float value, bool tcm) {
    m_core->memory.write<uint32_t>(arm7, address, std::bit_cast<uint32_t>(value), tcm);
}

// void Nds::writeRamf64(bool arm7, uint32_t address, double value, bool tcm) {
//     m_core->memory.write<uint64_t>(arm7, address, std::bit_cast<uint64_t>(value), tcm);
// }

void Nds::writeMap(uint32_t sAddress, uint32_t size, const std::vector<uint8_t>& buffer) {
    m_core->memory.writeMap(sAddress, size, buffer.data());
}
