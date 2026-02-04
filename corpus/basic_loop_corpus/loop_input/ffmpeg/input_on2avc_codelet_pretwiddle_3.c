#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int tab_step;
int order1;
float *src2;
float *out;
double *tab;
int i;
int j;

void init_vars() {
    // Set problem size to achieve approximately 0.01 seconds runtime
    // Heuristic: aim for moderate sizes with ~1M to 10M FLOPs
    order1 = 512;
    tab_step = 1024;

    // Allocate arrays
    src2 = (float*)aligned_alloc(32, order1 * sizeof(float));
    out = (float*)aligned_alloc(32, tab_step * sizeof(float));
    tab = (double*)aligned_alloc(32, order1 * tab_step * sizeof(double));

    // Initialize data to prevent NaN or extreme values affecting performance
    for (j = 0; j < order1; j++) {
        src2[j] = 1.0f / (j + 1);
    }

    for (i = 0; i < tab_step; i++) {
        out[i] = 0.0f;
        for (j = 0; j < order1; j++) {
            tab[j * tab_step + i] = 1.0 / (i + j + 1); // Fill in column-major like access
        }
    }
}