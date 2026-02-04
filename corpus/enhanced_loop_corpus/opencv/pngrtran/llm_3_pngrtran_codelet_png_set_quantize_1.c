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
    // Variant 2: Reverse consecutive memory access
    // Traverse the array from last element to first
    for (i = num_palette - 1; i >= 0; i--)
        quantize_sort[i] = (png_byte)i;
}
