#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float c[3][3];
extern  float a[3][3];
extern  float b[3][3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Use row-major stride access with pointer arithmetic
    float (*ap)[3] = a;
    float (*bp)[3] = b;
    float (*cp)[3] = c;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float sum = 0.F;
            const float* a_row = ap[i];
            float* b_col = &bp[0][j];
            for (int k = 0; k < 3; k++) {
                sum += a_row[k] * b_col[3*k];  // Strided access for column j of b
            }
            cp[i][j] = sum;
        }
    }
}
