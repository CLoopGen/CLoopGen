#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *b;
extern size_t blen;
extern size_t i;
extern uint64_t r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (process array from end to start)
    for (r = 0, i = 0; i < blen; i++) {
        r <<= 8;
        r |= b[blen - 1 - i];
    }
}
