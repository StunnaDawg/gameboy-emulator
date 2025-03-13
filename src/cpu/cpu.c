#include <stdio.h>
#include "../../include/cpu/cpu.h"

// ┌-> Carry
// ┌-+> Subtraction
// | |
// 1111 0000
// | |
// └-+> Zero
//  └-> Half Carry

//========================================
// Flag helper function logic
//========================================

// Set or clear a flag
void set_flag(CPU *cpu, uint8_t flag, bool value) {
    if (value) {
        cpu->f |= (1 << flag);  // Set the flag
    } else {
        cpu->f &= ~(1 << flag); // Clear the flag
    }
}

// Get flag value
bool get_flag(CPU *cpu, uint8_t flag) {
    return (cpu->f & (1 << flag)) != 0;
}

//-----------------------
// Register pair helpers
//-----------------------

// BC Getter
uint16_t get_bc(const CPU *cpu) {
    return (cpu->b << 8) | cpu->c;
}

// BC Setter
void set_bc(CPU *cpu, uint16_t value) {
    cpu->b = (value >> 8) & 0xFF; // high byte
    cpu->c = value & 0xFF; // low byte
}

// HL Getter
uint16_t get_hl(const CPU *cpu) {
    return (cpu->h << 8) | cpu->l;
}

// HL Setter
void set_hl(CPU *cpu, uint16_t value) {
    cpu->h = (value >> 8) & 0xFF; // high byte
    cpu->l = value & 0xFF; // low byte
}

// AF Getter
uint16_t get_af(const CPU *cpu) {
    return (cpu->a << 8) | cpu->f;
}

// AF Setter
void set_af(CPU *cpu, uint16_t value) {
    cpu->a = (value >> 8) & 0xFF; // high byte
    cpu->f = value & 0xFF; // low byte
}

// Flags to register function 
uint8_t flags_to_register(FlagsRegisters flags) {
    return (flags.zero << ZERO_FLAG_BYTE_POSITION) |
        (flags.subtraction << SUBTRACT_FLAG_BYTE_POSITION) |
        (flags.half_carry << HALF_CARRY_FLAG_BYTE_POSITION) |
        (flags.carry << CARRY_FLAG_BYTE_POSITION);
}

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
