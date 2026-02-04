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
    nb_samples = 16777216; // ~16M samples, target ~0.01s runtime on modern CPU

    dpp = (struct Decorr*)aligned_alloc(32, sizeof(struct Decorr));
    samples_l = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    samples_r = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));

    if (!dpp || !samples_l || !samples_r) {
        exit(1);
    }

    memset(dpp, 0, sizeof(struct Decorr));
    dpp->delta = 16;
    dpp->weightA = 128;
    dpp->weightB = 128;
    dpp->samplesA[0] = 1000;
    dpp->samplesA[1] = 990;
    dpp->samplesB[0] = 1000;
    dpp->samplesB[1] = 990;

    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = ((j + 1) * 751) % 5000;
        samples_r[j] = ((j + 1) * 926) % 5000;
    }
}