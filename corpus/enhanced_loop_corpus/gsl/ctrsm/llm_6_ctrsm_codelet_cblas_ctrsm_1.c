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
        for (j = 0; j < n2; j++) {
            int idx = 2 * (ldb * i + j);
            float temp_real = B_float[idx];
            float temp_imag = B_float[idx + 1];
            B_float[idx]     = alpha_real * temp_real - alpha_imag * temp_imag;
            B_float[idx + 1] = alpha_real * temp_imag + alpha_imag * temp_real;
        }
    }
}
