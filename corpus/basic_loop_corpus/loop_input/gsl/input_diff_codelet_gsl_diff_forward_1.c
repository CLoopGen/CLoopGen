#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int k;
double a[3] = {0.0, 1.0, 2.0};
double d[3] = {1.0, 2.0, 3.0};

void init_vars() {
    // No dynamic allocation needed; static arrays are of fixed size 3
    // Ensure initial values prevent out-of-bounds access during loop execution
    // Given loop bounds: k from 1 to 3, i from 0 to 3-k-1, so max i+1 is 2, max i+k is 2
    // Current array size 3 is sufficient, indices accessed: a[0..2], d[0..2]
}