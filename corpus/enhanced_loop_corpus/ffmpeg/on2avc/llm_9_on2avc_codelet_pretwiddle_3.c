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
    // Variant 2: Reduced computational load with modified trip count and simplified computation
    int step_size = (tab_step > 8) ? 2 : 1; // Increase step size based on problem size
    for (i = 0; i < tab_step; i += step_size) {
        double sum = 0;
        // Reduce effective iterations in inner loop for lower intensity
        int reduced_order = (order1 > 10) ? order1 / 2 : order1;
        for (j = 0; j < reduced_order; j++) {
            sum += src2[j] * tab[j * tab_step + i]; // Simplified access pattern
        }
        out[i] += (order1 > 10) ? sum * 0.5 : sum; // Scale down result if large order
    }
    // Ensure all outputs are touched even with larger step
    for (i = 1; i < tab_step; i += step_size) {
        if (i > 0) out[i] += out[i-1] * 0.1; // Light dependency to maintain validity
    }
}
