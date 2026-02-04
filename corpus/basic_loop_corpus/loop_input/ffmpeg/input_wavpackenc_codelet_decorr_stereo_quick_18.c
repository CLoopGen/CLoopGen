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

int32_t *in_left;
int32_t *in_right;
int32_t *out_left;
int32_t *out_right;
int nb_samples;
struct Decorr *dpp;
int m;
int i;
int k;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256MB total, ensures loop takes ~0.01s+
    nb_samples = data_size / sizeof(int32_t);

    in_left = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    in_right = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    out_left = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    out_right = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));

    dpp = (struct Decorr*)aligned_alloc(32, sizeof(struct Decorr));
    memset(dpp, 0, sizeof(struct Decorr));

    dpp->delta = 16;
    dpp->weightA = 1024;
    dpp->weightB = 1024;

    for (int idx = 0; idx < 8; idx++) {
        dpp->samplesA[idx] = (idx + 1) * 17;
        dpp->samplesB[idx] = (idx + 1) * 19;
    }

    for (int idx = 0; idx < nb_samples; idx++) {
        in_left[idx] = (int32_t)(rand() % 2048);
        in_right[idx] = (int32_t)(rand() % 2048);
    }

    m = 0;
    k = 1;

    for (int idx = 0; idx < nb_samples; idx++) {
        out_left[idx] = 0;
        out_right[idx] = 0;
    }
}