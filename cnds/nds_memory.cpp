#include "nds.hpp"


// Read memory methods
uint8_t Nds::readRamu8(uint32_t address) {
    return m_core->memory.readRam<uint8_t>(address);
}

uint16_t Nds::readRamu16(uint32_t address) {
    return m_core->memory.readRam<uint16_t>(address);
}

uint32_t Nds::readRamu32(uint32_t address) {
    return m_core->memory.readRam<uint32_t>(address);
}

uint64_t Nds::readRamu64(uint32_t address) {
    return m_core->memory.readRam<uint64_t>(address);
}

int8_t Nds::readRami8(uint32_t address) {
    return m_core->memory.readRam<int8_t>(address);
}

int16_t Nds::readRami16(uint32_t address) {
    return m_core->memory.readRam<int16_t>(address);
}

int32_t Nds::readRami32(uint32_t address) {
    return m_core->memory.readRam<int32_t>(address);
}

int64_t Nds::readRami64(uint32_t address) {
    return m_core->memory.readRam<int64_t>(address);
}

float Nds::readRamf32(uint32_t address) {
    return m_core->memory.readRam<float>(address);
}

double Nds::readRamf64(uint32_t address) {
    return m_core->memory.readRam<double>(address);
}

std::vector<uint8_t> Nds::readMap(uint32_t sAddress, uint32_t eAddress) {
    uint32_t size = eAddress - sAddress + 1;
    std::vector<uint8_t> buffer(size);
    m_core->memory.readMap(sAddress, eAddress, buffer.data());
    return std::move(buffer);
}

// Write memory methods
void Nds::writeRamu8(uint32_t address, uint8_t value) {
    m_core->memory.writeRam<uint8_t>(address, value);
}

void Nds::writeRamu16(uint32_t address, uint16_t value) {
    m_core->memory.writeRam<uint16_t>(address, value);
}

void Nds::writeRamu32(uint32_t address, uint32_t value) {
    m_core->memory.writeRam<uint32_t>(address, value);
}

void Nds::writeRamu64(uint32_t address, uint64_t value) {
    m_core->memory.writeRam<uint64_t>(address, value);
}

void Nds::writeRami8(uint32_t address, int8_t value) {
    m_core->memory.writeRam<int8_t>(address, value);
}

void Nds::writeRami16(uint32_t address, int16_t value) {
    m_core->memory.writeRam<int16_t>(address, value);
}

void Nds::writeRami32(uint32_t address, int32_t value) {
    m_core->memory.writeRam<int32_t>(address, value);
}

void Nds::writeRami64(uint32_t address, int64_t value) {
    m_core->memory.writeRam<int64_t>(address, value);
}

void Nds::writeRamf32(uint32_t address, float value) {
    m_core->memory.writeRam<float>(address, value);
}

void Nds::writeRamf64(uint32_t address, double value) {
    m_core->memory.writeRam<double>(address, value);
}

void Nds::writeMap(uint32_t sAddress, uint32_t size, const std::vector<uint8_t>& buffer) {
    m_core->memory.writeMap(sAddress, size, buffer.data());
}
