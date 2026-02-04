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
    // Outer loop simulates chunked processing by iterating over groups of bits
    for (uint64_t chunk = 0; chunk < (bits + 7) / 8; chunk++) {
        for (j = chunk * 8; j < bits && j < (chunk + 1) * 8; j++) {
            bitval = (value & ((uint64_t)1 << (bits - 1 - j))) != 0;
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
