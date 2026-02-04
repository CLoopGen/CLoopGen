#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int k;
double a[4] = {1.0, 2.0, 3.0, 4.0};
double d[4] = {10.0, 20.0, 30.0, 40.0};

void init_vars() {
    // No additional initialization needed beyond static initializers
    // since array sizes are fixed and loop bounds are safe with k from 1 to 4
}