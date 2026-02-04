#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char UINT8;

typedef int (*ODITHER_MATRIX_PTR)[16];

typedef long JLONG;

extern  UINT8 base_dither_matrix[16][16];
extern ODITHER_MATRIX_PTR odither;
extern int j;
extern int k;
extern JLONG num;
extern JLONG den;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j, k;
JLONG num;
JLONG den = 16 * 16;
for (j = 0; j < 16; j += 2) {
    for (k = 0; k < 16; k += 2) {
        JLONG val1 = (JLONG)base_dither_matrix[j][k];
        JLONG val2 = (j + 1 < 16 && k + 1 < 16) ? (JLONG)base_dither_matrix[j+1][k+1] : val1;
        num = ((val1 + val2) * 255) / 2;
        odither[j][k] = (int)(num / den);
        if (j + 1 < 16) odither[j+1][k] = odither[j][k];
        if (k + 1 < 16) odither[j][k+1] = odither[j][k];
        if (j + 1 < 16 && k + 1 < 16) odither[j+1][k+1] = odither[j][k];
    }
}
}
