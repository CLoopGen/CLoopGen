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
for (j = 0; j < 8; j++) {
    for (k = 0; k < 8; k++) {
        INT32 temp1 = (INT32)base_dither_matrix[j*2][k*2];
        INT32 temp2 = (INT32)base_dither_matrix[j*2+1][k*2+1];
        num = ((256 - 1 - temp1 - temp2)) * 255;
        int result = (num < 0 ? -((-num + den - 1) / den) : (num + den - 1) / den);
        odither[j*2][k*2] = result;
        odither[j*2+1][k*2+1] = result;
        odither[j*2][k*2+1] = result;
        odither[j*2+1][k*2] = result;
    }
}
}
