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
    for (j = 0; j < n2; j++) {
        if (!((i + j) % 2)) {
            const float Bij_real = (((float *)B)[2 * (ldb * i + j)]);
            const float Bij_imag = (((float *)B)[2 * (ldb * i + j) + 1]);
            (((float *)B)[2 * (ldb * i + j)]) = alpha_real * Bij_real - alpha_imag * Bij_imag;
            (((float *)B)[2 * (ldb * i + j) + 1]) = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    }
}
}
