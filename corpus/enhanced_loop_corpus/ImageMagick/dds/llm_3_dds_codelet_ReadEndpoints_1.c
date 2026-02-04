#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _BC7Colors {
    unsigned char r[6];
    unsigned char g[6];
    unsigned char b[6];
    unsigned char a[6];
} BC7Colors;

extern BC7Colors *endpoints;
extern size_t num_subsets;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride of 2, writing only to even indices (simulating a strided pattern)
    // This variant assumes the effective range is halved to maintain bounds safety
    size_t limit = (num_subsets * 2 + 1) / 2; // Ensures i*2 does not exceed original bound
    for (i = 0; i < limit; i++) {
        endpoints->a[i * 2] = 255;
    }
}
