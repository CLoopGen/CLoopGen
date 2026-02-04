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
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to target ~0.01s runtime on modern CPU
    nb_samples = data_size / sizeof(int32_t);

    in_left = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    in_right = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    out_left = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    out_right = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    dpp = (struct Decorr*)aligned_alloc(32, sizeof(struct Decorr));

    if (!in_left || !in_right || !out_left || !out_right || !dpp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize input data with pseudo-random but deterministic values
    srand(0);
    for (int j = 0; j < nb_samples; j++) {
        in_left[j] = rand() % 2000 - 1000;
        in_right[j] = rand() % 2000 - 1000;
    }

    // Initialize dpp fields
    dpp->delta = 16;
    dpp->value = 0;
    dpp->weightA = 0;
    dpp->weightB = 0;
    dpp->sumA = 0;
    dpp->sumB = 0;

    // Initialize samplesA and samplesB arrays
    for (int j = 0; j < 8; j++) {
        dpp->samplesA[j] = (j == 0) ? 100 : 90;
        dpp->samplesB[j] = (j == 0) ? 100 : 90;
    }
}