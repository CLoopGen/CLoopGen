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
    for (j = 0; j < 256; j++) {
        int row = j / 16;
        int col = j % 16;
        num = ((INT32)((16 * 16) - 1 - 2 * ((int)base_dither_matrix[row][col]))) * 255;
        odither[row][col] = (int)(num < 0 ? -((-num) / den) : num / den);
    }
}
