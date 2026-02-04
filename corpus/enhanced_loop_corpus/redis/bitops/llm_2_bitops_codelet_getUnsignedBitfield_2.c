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
    // Variant 1: Consecutive Memory Access (unrolled by 2 for stride simulation)
    uint64_t temp_offset = offset;
    uint64_t temp_value = value;
    for (j = 0; j < bits; j += 2) {
        // Access two consecutive bytes when possible to promote spatial locality
        uint64_t byte1 = temp_offset >> 3;
        uint64_t bit1 = 7 - (temp_offset & 7);
        uint64_t byteval1 = p[byte1];
        uint64_t bitval1 = (byteval1 >> bit1) & 1;

        temp_value = (temp_value << 1) | bitval1;
        temp_offset++;

        if (j + 1 < bits) { // Handle boundary
            uint64_t byte2 = temp_offset >> 3;
            uint64_t bit2 = 7 - (temp_offset & 7);
            uint64_t byteval2 = p[byte2];
            uint64_t bitval2 = (byteval2 >> bit2) & 1;

            temp_value = (temp_value << 1) | bitval2;
            temp_offset++;
        }
    }
    value = temp_value;
    offset = temp_offset;
}
