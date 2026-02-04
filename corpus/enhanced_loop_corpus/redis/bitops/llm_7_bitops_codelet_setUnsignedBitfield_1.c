#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *p;
extern uint64_t offset;
extern uint64_t bits;
extern uint64_t value;
extern uint64_t byte;
extern uint64_t bit;
extern uint64_t byteval;
extern uint64_t bitval;
extern uint64_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_offset = offset;
    uint64_t temp_value = value;
    for (j = 0; j < bits; j++) {
        uint64_t eff_bit = bits - 1 - j;
        uint64_t bitval = (temp_value >> eff_bit) & 1;
        uint64_t byte_idx = local_offset >> 3;
        uint64_t bit_idx = 7 - (local_offset & 7);
        uint64_t old_byte = p[byte_idx];
        uint64_t masked_byte = old_byte & ~(1ULL << bit_idx);
        uint64_t new_byte = masked_byte | (bitval << bit_idx);
        p[byte_idx] = (unsigned char)new_byte;
        local_offset++;
    }
    offset = local_offset;
}
