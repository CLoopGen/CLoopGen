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
    // Variant 1: Consecutive Memory Access with Prefetching Pattern
    // Instead of updating 'offset' per bit, we precompute the bytes affected and access them consecutively.
    // This variant groups byte updates to improve cache locality.

    uint64_t end_offset = offset + bits;
    uint64_t start_byte = offset >> 3;
    uint64_t end_byte = (end_offset + 7) >> 3;
    
    // Pre-load and process bytes in increasing order with sequential access
    for (uint64_t b = start_byte; b < end_byte; b++) {
        uint64_t new_byteval = 0;
        for (int local_bit = 7; local_bit >= 0; local_bit--) {
            uint64_t current_offset = (b << 3) + (7 - local_bit);
            if (current_offset < offset || current_offset >= end_offset) continue;

            uint64_t j = current_offset - offset;
            uint64_t bitval = (value & ((uint64_t)1 << (bits - 1 - j))) != 0;
            new_byteval |= bitval << local_bit;
        }
        // Merge with existing memory for unmodified bits
        uint64_t merged = (p[b] & 0xFF) & ~(0xFF >> (8 - ((end_offset - b * 8) & 7)) & (0xFF << ((b * 8 + 8 - end_offset) & 7)));
        merged |= new_byteval;
        p[b] = merged & 255;
    }
    offset = end_offset; // Update offset once at the end
}
