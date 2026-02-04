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
    // Variant 2: Strided access with a fixed step (stride of 2), processing every second element first, then the odd positions
    size_t total = num_subsets * 2;
    size_t stride = 2;
    
    // First pass: even indices (0, 2, 4, ...)
    for (i = 0; i < total; i += stride) {
        endpoints->r[i] <<= 1;
        endpoints->g[i] <<= 1;
        endpoints->b[i] <<= 1;
        endpoints->a[i] <<= 1;
    }
    
    // Second pass: odd indices (1, 3, 5, ...)
    for (i = 1; i < total; i += stride) {
        endpoints->r[i] <<= 1;
        endpoints->g[i] <<= 1;
        endpoints->b[i] <<= 1;
        endpoints->a[i] <<= 1;
    }
}
