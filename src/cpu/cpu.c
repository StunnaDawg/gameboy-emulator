#include <stdint.h>

typedef struct {
    uint8_t a, b, c, d, f, h, l;
} Registers;

uint16_t get_bc(const Registers *reg) {
    return (reg->b << 8) | reg->c;
};

void set_bc(Registers *reg, uint16_t value) {
    reg->b = (value >> 8) & 0xFF; // high byte
    reg->c = value & 0xFF; // low byte

}

uint16_t get_hl(const Registers *reg) {
    return (reg->h << 8) | reg->l;
};

void set_hl(Registers *reg, uint16_t value) {
    reg->h = (value >> 8) & 0xFF; // high byte
    reg->l = value & 0xFF; // low byte

}

uint16_t get_af(const Registers *reg) {
    return (reg->a << 8) | reg->f;
};

void set_af(Registers *reg, uint16_t value) {
    reg->a = (value >> 8) & 0xFF; // high byte
    reg->f = value & 0xFF; // low byte

}