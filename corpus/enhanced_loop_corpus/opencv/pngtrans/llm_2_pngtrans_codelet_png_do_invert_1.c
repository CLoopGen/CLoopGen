#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_bytep rp;
extern size_t i;
extern size_t istop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (process two elements per iteration consecutively)
    for (i = 0; i < istop; i += 2) {
        *rp = (png_byte)(~(*rp));
        *(rp + 1) = (png_byte)(~(*(rp + 1)));
        rp += 2;
    }
}
