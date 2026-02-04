#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char UINT8;

extern  UINT8 *bits;
extern int nsymbols;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop by accessing two elements per iteration
    for (len = 1; len <= 16; len += 2) {
        nsymbols += bits[len];
        if (len + 1 <= 16) {
            nsymbols += bits[len + 1];
        }
    }
}
