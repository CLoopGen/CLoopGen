#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float *in;
int size;
int i;
float cost;

void init_vars() {
    size = 64 * 1024 * 1024 / sizeof(float);
    in = (float*)aligned_alloc(32, size * sizeof(float));
    if (!in) exit(1);

    for (int idx = 0; idx < size; idx++) {
        in[idx] = (float)(idx % 1000) / 100.0f;
    }

    i = 0;
    cost = 0.0f;
}