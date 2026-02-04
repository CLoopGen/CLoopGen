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
        int base_idx = 2 * ldb * i;
        float ar = alpha_real;
        float ai = alpha_imag;
        for (j = 0; j < n2; j++) {
            int idx = base_idx + 2 * j;
            float br = B_float[idx];
            float bi = B_float[idx + 1];
            B_float[idx]     = ar * br - ai * bi;
            B_float[idx + 1] = ar * bi + ai * br;
        }
    }
}
