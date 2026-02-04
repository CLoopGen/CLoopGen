#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
    nb_samples = 16777216; // ~16.7M samples to target ~0.01 sec runtime

    dpp = (struct Decorr *)aligned_alloc(32, sizeof(struct Decorr));
    samples_l = (int32_t *)aligned_alloc(32, nb_samples * sizeof(int32_t));
    samples_r = (int32_t *)aligned_alloc(32, nb_samples * sizeof(int32_t));

    dpp->weightA = 512;
    dpp->weightB = 512;
    dpp->samplesB[0] = 1000;

    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = (j % 2) ? 1024 : -1024;
        samples_r[j] = (j % 2) ? -512 : 512;
    }

    for (int j = 1; j < 8; j++) {
        dpp->samplesA[j] = 0;
        dpp->samplesB[j] = 0;
    }
    dpp->sumA = 0;
    dpp->sumB = 0;
}