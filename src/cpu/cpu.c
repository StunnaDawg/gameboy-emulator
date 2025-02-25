#include <stdint.h>
#include <stdbool.h>

// ┌-> Carry
// ┌-+> Subtraction
// | |
// 1111 0000
// | |
// └-+> Zero
//  └-> Half Carry

typedef struct {
    uint8_t a, b, c, d, f, h, l;
} Registers;

// typedef struct {
//  bool zero, carry, halfCarry, subtraction
// } FlagRegisters;


typedef struct {
    uint8_t carry      : 1;
    uint8_t zero       : 1;
    uint8_t halfCarry  : 1;
    uint8_t subtraction : 1;
} FlagsRegisters;



// Flag Const
const uint8_t ZERO_FLAG_BYTE_POSITION = 7;
const uint8_t SUBTRACT_FLAG_BYTE_POSITION = 6;
const uint8_t HALF_CARRY_FLAG_BYTE_POSITION = 5;
const uint8_t CARRY_FLAG_BYTE_POSITION = 4;


// set it up baby
void set_carry(FlagsRegisters* self, uint8_t value) {
    self->carry = value;  // Use '->' to access members via pointer
}




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


// Flags 

// impl std::convert::From<FlagsRegister> for u8  {
//     fn from(flag: FlagsRegister) -> u8 {
//         (if flag.zero       { 1 } else { 0 }) << ZERO_FLAG_BYTE_POSITION |
//         (if flag.subtract   { 1 } else { 0 }) << SUBTRACT_FLAG_BYTE_POSITION |
//         (if flag.half_carry { 1 } else { 0 }) << HALF_CARRY_FLAG_BYTE_POSITION |
//         (if flag.carry      { 1 } else { 0 }) << CARRY_FLAG_BYTE_POSITION
//     }
// }

uint8_t flags_to_register(FlagsRegisters flags) {
    return (flags.zero << ZERO_FLAG_BYTE_POSITION) |
        (flags.subtraction << SUBTRACT_FLAG_BYTE_POSITION) |
        (flags.halfCarry << HALF_CARRY_FLAG_BYTE_POSITION) |
        (flags.carry << CARRY_FLAG_BYTE_POSITION);

}


uint8_t 


// impl std::convert::From<u8> for FlagsRegister {
//     fn from(byte: u8) -> Self {
//         let zero = ((byte >> ZERO_FLAG_BYTE_POSITION) & 0b1) != 0;
//         let subtract = ((byte >> SUBTRACT_FLAG_BYTE_POSITION) & 0b1) != 0;
//         let half_carry = ((byte >> HALF_CARRY_FLAG_BYTE_POSITION) & 0b1) != 0;
//         let carry = ((byte >> CARRY_FLAG_BYTE_POSITION) & 0b1) != 0;

//         FlagsRegister {
//             zero,
//             subtract,
//             half_carry,
//             carry
//         }
//     }
// }
