#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *light;
int plane;

void init_vars() {
    light = (double*)aligned_alloc(32, 3 * sizeof(double));
    if (!light) {
        exit(1);
    }
    for (int i = 0; i < 3; ++i) {
        light[i] = 0.0;
    }
    plane = 0;
}