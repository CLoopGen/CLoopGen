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
    if (bits == 0) return;
    bitval = (value >> (bits - 1)) & 1;
    byte = offset >> 3;
    bit = 7 - (offset & 7);
    byteval = p[byte];
    byteval = (byteval & ~(1 << bit)) | (bitval << bit);
    p[byte] = byteval;
    offset++;

    for (j = 1; j < bits; j++) {
        uint64_t shifted_val = value >> (bits - 1 - j);
        bitval = shifted_val & 1;
        offset++;
        byte = offset >> 3;
        bit = 7 - (offset & 7);
        p[byte] = (p[byte] & ~(1 << bit)) | (bitval << bit);
    }
}
