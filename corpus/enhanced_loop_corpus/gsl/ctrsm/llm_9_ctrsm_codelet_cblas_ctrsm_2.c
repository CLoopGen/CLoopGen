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
const int step = (n1 > n2) ? 1 : 2;
for (i = 0; i < n1; i += step) {
    for (j = 0; j < n2; j++) {
        const float temp_real = (((float *)B)[2 * (ldb * i + j)]);
        const float temp_imag = (((float *)B)[2 * (ldb * i + j) + 1]);

        float result_real = alpha_real * temp_real - alpha_imag * temp_imag;
        float result_imag = alpha_real * temp_imag + alpha_imag * temp_real;

        for (int k = 0; k < 2; k++) {
            result_real = alpha_real * result_real - alpha_imag * result_imag;
            result_imag = alpha_real * result_imag + alpha_imag * result_real;
        }

        (((float *)B)[2 * (ldb * i + j)]) = result_real;
        (((float *)B)[2 * (ldb * i + j) + 1]) = result_imag;
    }
}
}
