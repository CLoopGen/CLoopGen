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
    nb_samples = 16777216; // ~64 MB of input (16M * 4 bytes * 2 channels), target ~0.01-0.05 sec runtime

    dpp = (struct Decorr *)aligned_alloc(32, sizeof(struct Decorr));
    samples_l = (int32_t *)aligned_alloc(32, nb_samples * sizeof(int32_t));
    samples_r = (int32_t *)aligned_alloc(32, nb_samples * sizeof(int32_t));

    if (!dpp || !samples_l || !samples_r) {
        exit(1);
    }

    memset(dpp, 0, sizeof(struct Decorr));
    dpp->weightA = 512;
    dpp->weightB = 512;
    dpp->samplesA[0] = 1000;
    dpp->samplesB[0] = 1000;

    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = ((j + 1) * 751) % 8192;
        samples_r[j] = ((j + 1) * 1337) % 8192;
    }
}