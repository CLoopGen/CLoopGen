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
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements, adjust for ~0.01s runtime
    nb_samples = data_size / sizeof(int32_t);

    in_left = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    in_right = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    out_left = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    out_right = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));

    dpp = (struct Decorr*)aligned_alloc(32, sizeof(struct Decorr));
    dpp->delta = 16;
    dpp->value = 0;
    dpp->weightA = 512;
    dpp->weightB = 512;
    dpp->sumA = 0;
    dpp->sumB = 0;

    for (int j = 0; j < 8; j++) {
        dpp->samplesA[j] = (j == 0) ? 100 : 0;
        dpp->samplesB[j] = (j == 0) ? 100 : 0;
    }

    srand((unsigned int)time(NULL));
    for (int j = 0; j < nb_samples; j++) {
        in_left[j] = rand() % 2048 - 1024;
        in_right[j] = rand() % 2048 - 1024;
        out_left[j] = 0;
        out_right[j] = 0;
    }

    i = 0;
}