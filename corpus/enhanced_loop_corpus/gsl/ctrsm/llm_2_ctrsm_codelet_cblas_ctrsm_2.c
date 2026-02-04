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
    // Variant 1: Consecutive memory access by transposing iteration order for better spatial locality
    // We swap the loop order to traverse column-major like layout consecutively in inner loop
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            const ptrdiff_t idx = 2 * (ldb * i + j);
            const float Bij_real = ((float *)B)[idx];
            const float Bij_imag = ((float *)B)[idx + 1];
            ((float *)B)[idx]     = alpha_real * Bij_real - alpha_imag * Bij_imag;
            ((float *)B)[idx + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    }
}
