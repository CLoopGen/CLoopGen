#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UINT8;

typedef int (*ODITHER_MATRIX_PTR)[16];

typedef long INT32;

extern  UINT8 base_dither_matrix[16][16];
extern ODITHER_MATRIX_PTR odither;
extern int j;
extern int k;
extern INT32 num;
extern INT32 den;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Index-Array Based) Memory Access Pattern
    // Use precomputed linear indices to access matrix elements indirectly
    int indices[256];
    int idx = 0;
    for (int i = 0; i < 16; i++) {
        for (int l = 0; l < 16; l++) {
            indices[idx++] = i * 16 + l;
        }
    }
    for (idx = 0; idx < 256; idx++) {
        int row = indices[idx] / 16;
        int col = indices[idx] % 16;
        num = ((INT32)((16 * 16) - 1 - 2 * ((int)base_dither_matrix[row][col]))) * 255;
        odither[row][col] = (int)(num < 0 ? -((-num) / den) : num / den);
    }
}
