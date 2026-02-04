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
    for (j = 0; j < n2; j += 2) {
        const float Bij0_real = (((float *)B)[2 * (ldb * i + j)]);
        const float Bij0_imag = (((float *)B)[2 * (ldb * i + j) + 1]);
        const float Bij1_real = (((float *)B)[2 * (ldb * i + j + 1)]);
        const float Bij1_imag = (((float *)B)[2 * (ldb * i + j + 1) + 1]);
        
        (((float *)B)[2 * (ldb * i + j)]) = alpha_real * Bij0_real - alpha_imag * Bij0_imag;
        (((float *)B)[2 * (ldb * i + j) + 1]) = alpha_real * Bij0_imag + alpha_imag * Bij0_real;
        
        (((float *)B)[2 * (ldb * i + j + 1)]) = alpha_real * Bij1_real - alpha_imag * Bij1_imag;
        (((float *)B)[2 * (ldb * i + j + 1) + 1]) = alpha_real * Bij1_imag + alpha_imag * Bij1_real;
    }
}
}
