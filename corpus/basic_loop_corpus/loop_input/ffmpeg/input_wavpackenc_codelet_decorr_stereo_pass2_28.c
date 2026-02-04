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
int m;
int k;

void init_vars() {
    nb_samples = 16777216; // ~16M samples to target ~0.01 sec runtime on modern CPU

    dpp = (struct Decorr *)calloc(1, sizeof(struct Decorr));
    samples_l = (int32_t *)malloc(nb_samples * sizeof(int32_t));
    samples_r = (int32_t *)malloc(nb_samples * sizeof(int32_t));

    dpp->delta = 1;
    dpp->value = 0;
    dpp->weightA = 100;
    dpp->weightB = 100;

    for (int idx = 0; idx < 8; idx++) {
        dpp->samplesA[idx] = idx * 1000;
        dpp->samplesB[idx] = idx * 1000 + 500;
    }

    for (int idx = 0; idx < nb_samples; idx++) {
        samples_l[idx] = (idx % 997) * 3;
        samples_r[idx] = (idx % 997) * 5;
    }

    i = 0;
    m = 0;
    k = dpp->value & (8 - 1);
}