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

int32_t *in_left;
int32_t *in_right;
int32_t *out_left;
int32_t *out_right;
int nb_samples;
struct Decorr *dpp;
int i;

void init_vars() {
    const size_t data_size = 16777216; // 64 MB of samples (each sample is 4 bytes)
    nb_samples = data_size / sizeof(int32_t);

    in_left = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    in_right = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    out_left = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    out_right = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));

    dpp = (struct Decorr*)aligned_alloc(32, sizeof(struct Decorr));
    dpp->delta = 10;
    dpp->value = 0;
    dpp->weightA = 512;
    dpp->weightB = 512;
    dpp->sumA = 0;
    dpp->sumB = 0;

    for (int j = 0; j < 8; j++) {
        dpp->samplesA[j] = (j < 2) ? (1000 + j * 100) : 0;
        dpp->samplesB[j] = (j < 2) ? (1000 + j * 100) : 0;
    }

    for (int j = 0; j < nb_samples; j++) {
        in_left[j] = (int32_t)(1000 + (j % 1000));
        in_right[j] = (int32_t)(1500 + (j % 1000));
    }
}