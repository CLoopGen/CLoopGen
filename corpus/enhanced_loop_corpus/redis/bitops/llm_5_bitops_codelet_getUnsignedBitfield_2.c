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
    for (j = 0; j < bits; j++) {
        byte = offset >> 3;
        bit = 7 - (offset & 7);
        byteval = p[byte];
        bitval = (byteval >> bit) & 1;
        if (bitval) {
            value = (value << 1) | 1;
        } else {
            value = (value << 1);
        }
        offset++;
        if (value > 0x80000000) continue;
    }
}
