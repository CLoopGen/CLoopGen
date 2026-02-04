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
    // Variant 1: Strided memory access with stride of 2, wrapping around using modulo
    for (j = 0; j < 16; j++) {
        for (k = 0; k < 16; k++) {
            int idx_j = (j * 2) % 16;
            int idx_k = (k * 2) % 16;
            num = ((JLONG)((16 * 16) - 1 - 2 * ((int)base_dither_matrix[idx_j][idx_k]))) * 255;
            odither[idx_j][idx_k] = (int)(num < 0 ? -((-num) / den) : num / den);
        }
    }
}
