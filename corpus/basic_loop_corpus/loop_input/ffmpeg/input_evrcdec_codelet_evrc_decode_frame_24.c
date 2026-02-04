#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *samples;
int i;

static float samples_data[65536]; // ~256KB of data to target 0.01s runtime

void init_vars() {
    samples = samples_data;
    i = 0;
}