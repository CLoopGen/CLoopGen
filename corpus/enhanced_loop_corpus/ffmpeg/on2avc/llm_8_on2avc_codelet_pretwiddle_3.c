#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tab_step;
extern int order1;
extern float *src2;
extern float *out;
extern  double *tab;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    for (i = 0; i < tab_step; i++) {
        double sum = 0;
        int remainder = order1 % 4;
        // Process 4 elements at a time to increase computational density
        for (j = 0; j < order1 - remainder; j += 4) {
            sum += src2[j] * tab[j * tab_step + i] +
                   src2[j+1] * tab[(j+1) * tab_step + i] +
                   src2[j+2] * tab[(j+2) * tab_step + i] +
                   src2[j+3] * tab[(j+3) * tab_step + i];
        }
        // Handle remaining elements
        for (; j < order1; j++) {
            sum += src2[j] * tab[j * tab_step + i];
        }
        out[i] += sum * 1.001; // Slight modification to increase arithmetic complexity
    }
}
