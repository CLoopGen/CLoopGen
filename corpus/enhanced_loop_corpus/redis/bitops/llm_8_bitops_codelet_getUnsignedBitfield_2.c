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
    uint64_t j_inc = 2; // Process 2 bits per iteration to reduce trip count
    for (j = 0; j + 1 < bits; j += 2) {
        // First bit
        byte = offset >> 3;
        bit = 7 - (offset & 7);
        byteval = p[byte];
        bitval = (byteval >> bit) & 1;
        value = (value << 1) | bitval;
        offset++;

        // Second bit
        byte = offset >> 3;
        bit = 7 - (offset & 7);
        byteval = p[byte];
        bitval = (byteval >> bit) & 1;
        value = (value << 1) | bitval;
        offset++;
    }
    // Handle remaining bit if bits is odd
    if (j < bits) {
        byte = offset >> 3;
        bit = 7 - (offset & 7);
        byteval = p[byte];
        bitval = (byteval >> bit) & 1;
        value = (value << 1) | bitval;
        offset++;
    }
}
