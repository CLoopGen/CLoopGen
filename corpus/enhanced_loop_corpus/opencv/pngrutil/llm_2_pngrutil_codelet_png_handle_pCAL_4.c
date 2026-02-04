#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_bytep buf;
extern png_bytep units;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2 instead of 1)
    for (buf = units; *buf; buf += 2)
        if (*(buf + 1) == 0) break;
}
