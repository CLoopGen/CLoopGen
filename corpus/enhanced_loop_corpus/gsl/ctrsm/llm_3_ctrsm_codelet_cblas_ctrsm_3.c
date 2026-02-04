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
for (j = 0; j < n2; j++) {
    for (i = 0; i < n1; i++) {
        const int offset = 2 * (ldb * i + j);
        float *B_ptr = (float *)B + offset;
        const float Bij_real = B_ptr[0];
        const float Bij_imag = B_ptr[1];
        B_ptr[0] = alpha_real * Bij_real - alpha_imag * Bij_imag;
        B_ptr[1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
    }
}
}
