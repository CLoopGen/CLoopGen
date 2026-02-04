#include <stdio.h>

double x[131072];
int i;

void init_vars() {
    // No additional initialization needed beyond defining the array with correct size
    // The loop uses 2 * (1 << 16) = 131072 iterations, which matches the array size
}