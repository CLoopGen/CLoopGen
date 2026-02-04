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
    // Variant 2: Strided Memory Access Pattern
    // Instead of sequential bit-by-bit write, update every other byte first, then fill gaps (strided access).
    // Simulates non-unit stride to expose memory-level parallelism or test alignment behavior.

    // First pass: update even-indexed target bytes (stride of 2)
    for (j = 0; j < bits; j += 2) {
        uint64_t local_offset = offset + j;
        uint64_t byte_idx = local_offset >> 3;
        uint64_t bit_idx = 7 - (local_offset & 7);
        
        bitval = (value & ((uint64_t)1 << (bits - 1 - j))) != 0;
        byteval = p[byte_idx];
        byteval &= ~(1 << bit_idx);
        byteval |= bitval << bit_idx;
        p[byte_idx] = byteval & 255;
    }

    // Second pass: update odd-indexed target bytes (completes the strided pattern)
    for (j = 1; j < bits; j += 2) {
        uint64_t local_offset = offset + j;
        uint64_t byte_idx = local_offset >> 3;
        uint64_t bit_idx = 7 - (local_offset & 7);
        
        bitval = (value & ((uint64_t)1 << (bits - 1 - j))) != 0;
        byteval = p[byte_idx];
        byteval &= ~(1 << bit_idx);
        byteval |= bitval << bit_idx;
        p[byte_idx] = byteval & 255;
    }

    offset += bits; // Update offset after both passes
}
