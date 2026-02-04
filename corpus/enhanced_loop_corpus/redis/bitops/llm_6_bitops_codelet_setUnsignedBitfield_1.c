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
    uint64_t temp_bitval, temp_byte, temp_bit;
    for (j = 0; j < bits; j++) {
        temp_bitval = (value >> (bits - 1 - j)) & 1;
        temp_byte = offset >> 3;
        temp_bit = 7 - (offset & 7);
        uint64_t mask = ~(1ULL << temp_bit);
        byteval = p[temp_byte];
        byteval = (byteval & mask) | (temp_bitval << temp_bit);
        p[temp_byte] = (unsigned char)byteval;
        offset++;
    }
}
