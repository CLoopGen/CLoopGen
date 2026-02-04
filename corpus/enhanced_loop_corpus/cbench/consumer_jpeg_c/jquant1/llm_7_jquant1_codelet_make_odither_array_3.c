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
    INT32 prev_num = 0;
    for (j = 0; j < 16; j++) {
        for (k = 0; k < 16; k++) {
            num = ((INT32)((16 * 16) - 1 - 2 * ((int)base_dither_matrix[j][k]) + (prev_num & 0xFF))) * 255;
            odither[j][k] = (int)(num < 0 ? -((-num) / den) : num / den);
            prev_num = num;
        }
    }
}
