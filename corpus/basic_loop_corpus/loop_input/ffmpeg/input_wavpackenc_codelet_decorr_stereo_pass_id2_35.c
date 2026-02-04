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
int m;
int k;

void init_vars() {
    nb_samples = 16777216; // ~64 MB of input data (16M * 4 bytes per int32_t * 2 channels)

    dpp = (struct Decorr*)aligned_alloc(64, sizeof(struct Decorr));
    samples_l = (int32_t*)aligned_alloc(64, nb_samples * sizeof(int32_t));
    samples_r = (int32_t*)aligned_alloc(64, nb_samples * sizeof(int32_t));

    if (!dpp || !samples_l || !samples_r) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(dpp, 0, sizeof(struct Decorr));
    dpp->value = 0;
    dpp->weightA = 100;
    dpp->weightB = 100;
    for (int idx = 0; idx < 8; idx++) {
        dpp->samplesA[idx] = (idx + 1) * 100;
        dpp->samplesB[idx] = (idx + 1) * 200;
    }
    dpp->sumA = 0;
    dpp->sumB = 0;

    for (int idx = 0; idx < nb_samples; idx++) {
        samples_l[idx] = (int32_t)(idx * 1.5);
        samples_r[idx] = (int32_t)(idx * 2.5);
    }

    i = 0;
    m = 0;
    k = dpp->value & (8 - 1);
}