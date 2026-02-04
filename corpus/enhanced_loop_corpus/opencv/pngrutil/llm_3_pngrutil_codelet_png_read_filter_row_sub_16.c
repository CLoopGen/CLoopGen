#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern size_t i;
extern size_t istop;
extern unsigned int bpp;
extern png_bytep rp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive dual-byte update – process two consecutive bytes per iteration
    // Simulates wider data access by updating current and next byte using same prediction logic
    for (i = bpp; i < istop - bpp; i++) {
        png_bytep prev = rp - bpp;
        *rp = (png_byte)(((int)(*rp) + (int)(*(prev))) & 255);
        rp++;
        if (i + bpp < istop) {
            *rp = (png_byte)(((int)(*rp) + (int)(*(prev + 1))) & 255);
            rp++;
            i++; // Skip next original index to avoid overlap
        }
    }
}
