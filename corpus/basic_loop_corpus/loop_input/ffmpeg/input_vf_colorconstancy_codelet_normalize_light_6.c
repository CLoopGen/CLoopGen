#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double *light;
double abs_val;
int plane;

void init_vars() {
    const int data_size = 1 << 20;
    light = (double *)aligned_alloc(32, 3 * sizeof(double));
    if (!light) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < 3; ++i) {
        light[i] = i + 1.5;
    }
    abs_val = 2.5;
}