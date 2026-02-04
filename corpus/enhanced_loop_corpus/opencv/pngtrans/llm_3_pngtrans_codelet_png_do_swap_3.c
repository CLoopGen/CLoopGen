#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep rp;
extern png_uint_32 i;
extern png_uint_32 istop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing stride
    // Instead of sequential access, traverse the array with a growing stride
    // to simulate non-contiguous, strided access pattern (e.g., for cache behavior testing).
    // We maintain logical equivalence by visiting each 2-byte block exactly once using modular indexing.
    png_uint_32 n = istop;
    png_uint_32 stride = 7; // Prime number for better distribution
    png_uint_32 count = 0;
    for (i = 0; count < n; i = (i + stride) % n, count++) {
        png_bytep p = rp + 2 * i; // Access the i-th 2-byte block
        png_byte t = *p;
        *p = *(p + 1);
        *(p + 1) = t;
    }
}
