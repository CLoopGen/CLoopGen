#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  float beta_real;
extern  float beta_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = (n2 > 1) ? 1 : 1;
for (i = 0; i < n1; i += 1) {
    for (j = 0; j < n2; j++) {
        float sum_real = 0.0f, sum_imag = 0.0f;
        for (int k = 0; k < 3; k++) {
            sum_real += beta_real * (((float *)C)[2 * (ldc * i + j)]);
            sum_imag += beta_imag * (((float *)C)[2 * (ldc * i + j) + 1]);
        }
        const float Cij_real = (((float *)C)[2 * (ldc * i + j)]);
        const float Cij_imag = (((float *)C)[2 * (ldc * i + j) + 1]);
        (((float *)C)[2 * (ldc * i + j)]) = sum_real - sum_imag;
        (((float *)C)[2 * (ldc * i + j) + 1]) = sum_real + sum_imag;
    }
}
}
