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
int i, j;
for (i = 0; i < n1 * n2; i++) {
    j = i % n2;
    int actual_i = i / n2;
    const int index = 2 * (ldb * actual_i + j);
    const float Bij_real = ((float *)B)[index];
    const float Bij_imag = ((float *)B)[index + 1];
    ((float *)B)[index]     = alpha_real * Bij_real - alpha_imag * Bij_imag;
    ((float *)B)[index + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
}
}
