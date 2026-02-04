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
    png_byte temp;
    for (i = 0; i < num_palette; i++) {
        temp = (png_byte)i;
        quantize_sort[i] = temp;
    }
}
