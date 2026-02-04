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
    // Variant 1: Consecutive memory access by reordering computation to improve spatial locality
    // We transpose the access pattern to iterate over `tab` in row-major (consecutive) order
    double temp_sum[tab_step];
    
    // Initialize temporary sums
    for (i = 0; i < tab_step; i++) {
        temp_sum[i] = 0;
    }

    for (j = 0; j < order1; j++) {
        float src_val = src2[j];
        int base_idx = j * tab_step;
        for (i = 0; i < tab_step; i++) {
            temp_sum[i] += src_val * tab[base_idx + i];
        }
    }

    // Accumulate results into out
    for (i = 0; i < tab_step; i++) {
        out[i] += temp_sum[i];
    }
}
