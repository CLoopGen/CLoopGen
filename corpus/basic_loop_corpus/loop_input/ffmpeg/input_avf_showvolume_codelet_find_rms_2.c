#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *src;
int nb_samples;
float *rms;
float factor;
int i;

void init_vars() {
    nb_samples = 64 * 1024 * 1024; // ~64M samples, adjust for ~0.01s runtime
    src = (float *)aligned_alloc(32, nb_samples * sizeof(float));
    rms = (float *)aligned_alloc(32, sizeof(float));
    
    if (!src || !rms) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < nb_samples; j++) {
        src[j] = (float)(rand() % 1000) / 1000.0f;
    }
    
    *rms = 0.1f;
    factor = 0.001f;
}