#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

struct Decorr {
    int delta;
    int value;
    int weightA;
    int weightB;
    int samplesA[8];
    int samplesB[8];
    int sumA;
    int sumB;
};

struct Decorr *dpp;
int32_t *samples_l;
int32_t *samples_r;
int nb_samples;
int i;

void init_vars() {
    // Allocate dpp structure
    dpp = (struct Decorr *)calloc(1, sizeof(struct Decorr));
    if (!dpp) exit(1);

    // Initialize dpp fields
    dpp->delta = 10;
    dpp->value = 0;
    dpp->weightA = 512;
    dpp->weightB = 512;
    dpp->sumA = 0;
    dpp->sumB = 0;
    dpp->samplesA[0] = 4000;
    dpp->samplesA[1] = 3900;
    dpp->samplesB[0] = 4050;
    dpp->samplesB[1] = 3950;

    // Set number of samples to achieve ~0.01s runtime
    // Based on typical performance, ~4M samples takes ~0.01s
    nb_samples = 4194304;  // 2^22, roughly 16MB of data per channel

    // Allocate sample buffers
    samples_l = (int32_t *)calloc(nb_samples, sizeof(int32_t));
    samples_r = (int32_t *)calloc(nb_samples, sizeof(int32_t));
    if (!samples_l || !samples_r) exit(1);

    // Initialize sample data with non-zero values to ensure meaningful computation
    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = (j & 1023) - 512;
        samples_r[j] = ((j * 7) & 1023) - 512;
    }

    // Initialize loop index
    i = 0;
}