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
    uint64_t j_mod;
    for (j = 0; j < bits; j += 2) {
        for (j_mod = 0; j_mod < 2 && (j + j_mod) < bits; j_mod++) {
            uint64_t current_j = j + j_mod;
            bitval = (value & ((uint64_t)1 << (bits - 1 - current_j))) != 0;
            byte = offset >> 3;
            bit = 7 - (offset & 7);
            byteval = p[byte];
            byteval &= ~(1 << bit);
            byteval |= bitval << bit;
            p[byte] = byteval & 255;
            offset++;
        }
    }
}
