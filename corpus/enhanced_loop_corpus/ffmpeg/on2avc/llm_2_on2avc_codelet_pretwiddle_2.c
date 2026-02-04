#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *src;
extern int tab_step;
extern int order0;
extern float *out;
extern  double *tab;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (loop unrolling with stride-1 access)
    // Reorder computation to improve spatial locality by transposing tab access
    double temp_tab[order0];
    for (i = 0; i < tab_step; i++) {
        // Pre-load the i-th column of tab into a temporary array for consecutive access
        for (j = 0; j < order0; j++) {
            temp_tab[j] = tab[j * tab_step + i];
        }
        double sum = 0;
        for (j = 0; j < order0; j++) {
            sum += src[j] * temp_tab[j];  // Now accessing temp_tab consecutively
        }
        out[i] += sum;
    }
}
