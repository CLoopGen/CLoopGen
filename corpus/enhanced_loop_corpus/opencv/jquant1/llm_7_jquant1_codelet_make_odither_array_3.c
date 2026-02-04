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
    JLONG prev_num = 0;
    int offset = 0;
    for (j = 0; j < 16; j++) {
        for (k = 0; k < 16; k++) {
            num = ((JLONG)((16 * 16) - 1 - 2 * ((int)base_dither_matrix[j][k]) + offset)) * 255;
            odither[j][k] = (int)(num < 0 ? -((-num) / den) : num / den);
            offset = (int)(odither[j][k] & 1); // Introduce WAW and loop-carried dependency
        }
    }
}
