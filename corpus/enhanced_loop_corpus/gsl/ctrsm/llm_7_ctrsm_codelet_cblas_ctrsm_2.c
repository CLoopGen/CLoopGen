#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *B_float = (float *)B;
    for (i = 0; i < n1; i++) {
        int base_idx = ldb * i;
        float row_factor_real = (i % 2 == 0) ? alpha_real : -alpha_real;
        float row_factor_imag = (i % 2 == 0) ? alpha_imag : -alpha_imag;
        for (j = 0; j < n2; j++) {
            int idx = 2 * (base_idx + j);
            float Bij_real = B_float[idx];
            float Bij_imag = B_float[idx + 1];
            float result_real = row_factor_real * Bij_real - row_factor_imag * Bij_imag;
            float result_imag = row_factor_real * Bij_imag + row_factor_imag * Bij_real;
            B_float[idx]     = result_real;
            B_float[idx + 1] = result_imag;
        }
    }
}
