#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern int num_palette;
extern png_bytep quantize_sort;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, forward pass)
    // We assume num_palette is even for simplicity; if not, adjust accordingly.
    int stride = 2;
    int n = num_palette;
    
    // First pass: even indices
    for (i = 0; i < n; i += stride)
        quantize_sort[i] = (png_byte)i;

    // Second pass: odd indices
    for (i = 1; i < n; i += stride)
        quantize_sort[i] = (png_byte)i;
}
