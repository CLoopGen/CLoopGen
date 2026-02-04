#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
    nb_samples = 16777216; // ~64 MB of input data (16M * 4 bytes * 2 channels)

    dpp = (struct Decorr *)aligned_alloc(32, sizeof(struct Decorr));
    samples_l = (int32_t *)aligned_alloc(32, nb_samples * sizeof(int32_t));
    samples_r = (int32_t *)aligned_alloc(32, nb_samples * sizeof(int32_t));

    // Initialize dpp fields
    dpp->delta = 0;
    dpp->value = 0;
    dpp->weightA = 512;
    dpp->weightB = 512;
    dpp->sumA = 0;
    dpp->sumB = 0;

    for (int j = 0; j < 8; j++) {
        dpp->samplesA[j] = (j + 1) * 17;
        dpp->samplesB[j] = (j + 1) * 29;
    }

    // Initialize sample buffers with non-zero values to ensure meaningful computation
    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = (int32_t)(j * 31);
        samples_r[j] = (int32_t)(j * 47);
    }
}