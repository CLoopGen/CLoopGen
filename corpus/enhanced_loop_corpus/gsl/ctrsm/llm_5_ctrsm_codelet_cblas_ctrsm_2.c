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
    const int skip = (i % 3 == 0) ? 1 : 0;
    for (j = skip; j < n2; j++) {
        const int index = 2 * (ldb * i + j);
        const float Bij_real = (((float *)B)[index]);
        const float Bij_imag = (((float *)B)[index + 1]);
        const float temp_real = alpha_real * Bij_real - alpha_imag * Bij_imag;
        const float temp_imag = alpha_real * Bij_imag + alpha_imag * Bij_real;
        (((float *)B)[index]) = temp_real;
        (((float *)B)[index + 1]) = temp_imag;
    }
}
}
