#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char _usr_index;
extern unsigned char indexes[16];

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Strided memory access (write every 2nd element, then fill backwards)
    for (i = 0; i < 16; i += 2) {
        indexes[i] = index;
    }
    for (i = 15; i >= 0; i -= 2) {
        indexes[i] = index;
    }
}
