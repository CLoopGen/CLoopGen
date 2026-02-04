#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int k;
double a[3] = {0.0, 1.0, 2.0};
double d[3] = {1.0, 2.0, 3.0};

void init_vars() {
    // No additional initialization needed for base arrays as sizes are fixed at 3
    // Values already initialized statically
    // Ensure initial values are set such that no out-of-bounds access occurs
    // Loop runs with k from 1 to 3 and i from 0 to (3-k-1), which is valid for arrays of size 3
}