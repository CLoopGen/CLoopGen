#include <stdio.h>

double ten[10][2];
int i;
int j1[10][2];
int j2[10][2];
int j3[10][2];

void init_vars() {
    // All arrays are already at file scope and will be zero-initialized by default.
    // However, to ensure proper initialization and satisfy any dependencies,
    // we can explicitly set initial values if needed. The loop function will overwrite these anyway.
    // Since the array sizes are small (10x2), no additional large data is required.
    // The original loop runs over 10 iterations, so no changes to bounds are needed.
}