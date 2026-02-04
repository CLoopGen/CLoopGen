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
for (i = 0; i < n1; i++) {
    int base_i = 2 * ldb * i;
    for (j = 0; j < n2; j++) {
        int idx = base_i + 2 * j;
        const float *ptr = (const float *)B + idx;
        float Bij_real = ptr[0];
        float Bij_imag = ptr[1];
        float *B_ptr = (float *)B + idx;
        B_ptr[0] = alpha_real * Bij_real - alpha_imag * Bij_imag;
        B_ptr[1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
    }
}
}
