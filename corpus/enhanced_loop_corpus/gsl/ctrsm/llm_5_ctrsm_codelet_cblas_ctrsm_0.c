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
    if (i % 2 == 0) {
        for (j = 0; j < n2; j++) {
            const float Bij_real = (((float *)B)[2 * (ldb * i + j)]);
            const float Bij_imag = (((float *)B)[2 * (ldb * i + j) + 1]);
            (((float *)B)[2 * (ldb * i + j)]) = alpha_real * Bij_real - alpha_imag * Bij_imag;
            (((float *)B)[2 * (ldb * i + j) + 1]) = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    } else {
        for (j = 0; j < n2; j += 2) {
            if (j + 1 < n2) {
                const float Bij_real1 = (((float *)B)[2 * (ldb * i + j)]);
                const float Bij_imag1 = (((float *)B)[2 * (ldb * i + j) + 1]);
                const float Bij_real2 = (((float *)B)[2 * (ldb * i + j + 1)]);
                const float Bij_imag2 = (((float *)B)[2 * (ldb * i + j + 1) + 1]);

                (((float *)B)[2 * (ldb * i + j)]) = alpha_real * Bij_real1 - alpha_imag * Bij_imag1;
                (((float *)B)[2 * (ldb * i + j) + 1]) = alpha_real * Bij_imag1 + alpha_imag * Bij_real1;

                (((float *)B)[2 * (ldb * i + j + 1)]) = alpha_real * Bij_real2 - alpha_imag * Bij_imag2;
                (((float *)B)[2 * (ldb * i + j + 1) + 1]) = alpha_real * Bij_imag2 + alpha_imag * Bij_real2;
            } else {
                const float Bij_real = (((float *)B)[2 * (ldb * i + j)]);
                const float Bij_imag = (((float *)B)[2 * (ldb * i + j) + 1]);
                (((float *)B)[2 * (ldb * i + j)]) = alpha_real * Bij_real - alpha_imag * Bij_imag;
                (((float *)B)[2 * (ldb * i + j) + 1]) = alpha_real * Bij_imag + alpha_imag * Bij_real;
            }
        }
    }
}
}
