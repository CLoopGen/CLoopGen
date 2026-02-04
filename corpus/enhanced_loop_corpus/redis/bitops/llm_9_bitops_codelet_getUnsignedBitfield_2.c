#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *p;
extern uint64_t offset;
extern uint64_t bits;
extern uint64_t byte;
extern uint64_t bit;
extern uint64_t byteval;
extern uint64_t bitval;
extern uint64_t j;
extern uint64_t value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Increased computational intensity: unroll by 4 and use more arithmetic
    uint64_t base_offset, b, bv;
    uint64_t temp_value = value;

    for (j = 0; j + 3 < bits; j += 4) {
        // Unroll 4 iterations with expanded arithmetic

        // Iteration 1
        base_offset = offset;
        byte = base_offset >> 3;
        b = 7 - (base_offset & 7);
        bv = (p[byte] >> b) & 1;
        temp_value = (temp_value << 1) | bv;
        offset++;

        // Iteration 2
        base_offset = offset;
        byte = base_offset >> 3;
        b = 7 - (base_offset & 7);
        bv = (p[byte] >> b) & 1;
        temp_value = (temp_value << 1) | bv;
        offset++;

        // Iteration 3
        base_offset = offset;
        byte = base_offset >> 3;
        b = 7 - (base_offset & 7);
        bv = (p[byte] >> b) & 1;
        temp_value = (temp_value << 1) | bv;
        offset++;

        // Iteration 4
        base_offset = offset;
        byte = base_offset >> 3;
        b = 7 - (base_offset & 7);
        bv = (p[byte] >> b) & 1;
        temp_value = (temp_value << 1) | bv;
        offset++;
    }

    // Scalar cleanup for remaining bits
    for (; j < bits; j++) {
        byte = offset >> 3;
        bit = 7 - (offset & 7);
        byteval = p[byte];
        bitval = (byteval >> bit) & 1;
        temp_value = (temp_value << 1) | bitval;
        offset++;
    }

    value = temp_value;
}
