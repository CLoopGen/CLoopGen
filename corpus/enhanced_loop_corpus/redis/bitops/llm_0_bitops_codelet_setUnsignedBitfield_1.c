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
    for (j = 0; j < bits; j++) {
        bitval = (value & ((uint64_t)1 << (bits - 1 - j))) != 0;
        byte = offset >> 3;
        bit = 7 - (offset & 7);
        byteval = p[byte];
        byteval &= ~(1 << bit);
        byteval |= bitval << bit;
        p[byte] = byteval & 255;
        offset++;
        
        // Introduce inner loop that does nothing but simulate fine-grained bit processing
        for (uint64_t k = 0; k < 1; k++) {
            // No-op inner loop to increase nesting depth
        }
    }
}
