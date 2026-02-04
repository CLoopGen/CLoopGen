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
JLONG den = 16 * 16; // Assume den is initialized to this value for consistency
for (j = 0; j < 8; j++) {
    for (k = 0; k < 8; k++) {
        num = ((JLONG)(den - 1 - 4 * ((int)base_dither_matrix[j][k]))) * 127;
        odither[j][k] = (int)(num < 0 ? -((-num) / den) : num / den);
    }
}
}
