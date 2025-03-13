#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdbool.h>

// CPU Registers
typedef struct {
    uint8_t a, b, c, d, f, h, l;
    uint16_t sp, pc;       // stack pointer / program counter
    uint8_t memory[65536]; //64KB
} CPU; 

// CPU function prototypes
void initialize_cpu(CPU *cpu);
void execute_instructions(CPU *cpu);

// Flag position consts
const uint8_t ZERO_FLAG_BYTE_POSITION = 7;
const uint8_t SUBTRACT_FLAG_BYTE_POSITION = 6;
const uint8_t HALF_CARRY_FLAG_BYTE_POSITION = 5;
const uint8_t CARRY_FLAG_BYTE_POSITION = 4;

// Flag registers struct
typedef struct {
    uint8_t carry      : 1;
    uint8_t zero       : 1;
    uint8_t half_carry  : 1;
    uint8_t subtract : 1;
} FlagsRegisters;

// Flag helper functions (sets/clears specific flag in F register)
void set_flag(CPU *cpu, uint8_t flag, bool value);
bool get_flag(CPU *cpu, uint8_t flag);

// Register function prototypes 
uint16_t get_bc(const Registers *reg)
void set_bc(Registers *reg, uint16_t value); 
uint16_t get_hl(const Registers *reg);
void set_hl(Registers *reg, uint16_t value);
uint16_t get_af(const Registers *reg);
void set_af(Registers *reg, uint16_t value);

#endif // CPU_H