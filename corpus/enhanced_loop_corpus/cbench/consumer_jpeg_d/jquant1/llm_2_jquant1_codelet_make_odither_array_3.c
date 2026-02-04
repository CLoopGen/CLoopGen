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
for (k = 0; k < 16; k++) {
    for (j = 0; j < 16; j++) {
        INT32 temp = ((INT32)((16 * 16) - 1 - 2 * ((int)base_dither_matrix[j][k]))) * 255;
        odither[j][k] = (int)(temp < 0 ? -((-temp) / den) : temp / den);
    }
}
}
