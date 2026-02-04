#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float *src;
int nb_samples;
float *peak;
int i;

void init_vars() {
    nb_samples = 64 * 1024 * 1024 / sizeof(float);
    src = (float *)aligned_alloc(32, nb_samples * sizeof(float));
    peak = (float *)aligned_alloc(32, sizeof(float));

    if (!src || !peak) {
        exit(1);
    }

    *peak = 0.0f;
    for (int j = 0; j < nb_samples; j++) {
        src[j] = (float)((rand() % 2000) - 1000) / 100.0f;
    }
}