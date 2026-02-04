#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *coef;
int order;
int i;
int shift_val;
int high_idx;

void init_vars() {
    order = 65536; // Sufficient size to run loop for ~0.01s
    shift_val = 10;
    high_idx = 100;
    coef = (int*)aligned_alloc(32, order * sizeof(int));
    for (int idx = 0; idx < order; idx++) {
        coef[idx] = idx % 200; // Initialize with values in range [0, 199]
    }
}