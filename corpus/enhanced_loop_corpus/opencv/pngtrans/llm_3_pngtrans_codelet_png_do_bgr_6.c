#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_uint_32 row_width;
extern png_bytep rp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with indirect pointer via index array (simulated indirect access)
    png_uint_32 *indices = (png_uint_32*)malloc(row_width * sizeof(png_uint_32));
    if (!indices) return;
    for (png_uint_32 j = 0; j < row_width; j++) {
        indices[j] = j * 4; // Stride of 4 bytes per pixel (BGRA/RGBA format)
    }
    for (i = 0; i < row_width; i++) {
        png_bytep rp = row + indices[i];
        png_byte save = *rp;
        *rp = *(rp + 2);
        *(rp + 2) = save;
    }
    free(indices);
}
