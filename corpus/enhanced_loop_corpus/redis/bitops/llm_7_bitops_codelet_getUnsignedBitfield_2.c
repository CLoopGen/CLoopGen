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
    uint64_t carry = 0;
    for (j = 0; j < bits; j += 2) {
        uint64_t idx1 = (offset + j) >> 3;
        uint64_t bitpos1 = 7 - ((offset + j) & 7);
        uint64_t val1 = (p[idx1] >> bitpos1) & 1;

        uint64_t idx2 = (offset + j + 1) >> 3;
        uint64_t bitpos2 = 7 - ((offset + j + 1) & 7);
        uint64_t val2 = (p[idx2] >> bitpos2) & 1;

        carry = (carry << 2) | (val1 << 1) | val2;
    }
    if (bits & 1) {
        uint64_t last_byte = (offset + bits - 1) >> 3;
        uint64_t last_bit = 7 - ((offset + bits - 1) & 7);
        uint64_t last_val = (p[last_byte] >> last_bit) & 1;
        carry = (carry << 1) | last_val;
    }
    value = carry;
    offset += bits;
}
