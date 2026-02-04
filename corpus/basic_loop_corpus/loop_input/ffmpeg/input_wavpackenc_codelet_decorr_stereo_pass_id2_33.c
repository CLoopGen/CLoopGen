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
    nb_samples = 1048576; // ~1M samples, adjust for ~0.01 sec runtime

    dpp = (struct Decorr *)calloc(1, sizeof(struct Decorr));
    samples_l = (int32_t *)malloc(nb_samples * sizeof(int32_t));
    samples_r = (int32_t *)malloc(nb_samples * sizeof(int32_t));

    dpp->weightA = 10;
    dpp->weightB = 10;
    dpp->samplesA[0] = 1000;
    dpp->samplesA[1] = 990;
    dpp->samplesB[0] = 1000;
    dpp->samplesB[1] = 990;

    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = (j & 1) ? 100 : -100;
        samples_r[j] = (j & 1) ? 80 : -80;
    }
}