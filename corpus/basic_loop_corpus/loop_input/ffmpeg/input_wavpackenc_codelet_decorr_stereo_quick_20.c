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
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements to target ~0.01 sec runtime
    nb_samples = data_size / sizeof(int32_t);

    in_left = aligned_alloc(32, nb_samples * sizeof(int32_t));
    in_right = aligned_alloc(32, nb_samples * sizeof(int32_t));
    out_left = aligned_alloc(32, nb_samples * sizeof(int32_t));
    out_right = aligned_alloc(32, nb_samples * sizeof(int32_t));

    dpp = aligned_alloc(32, sizeof(struct Decorr));

    // Initialize dpp fields
    dpp->delta = 16;
    dpp->value = 0;
    dpp->weightA = 512;
    dpp->weightB = 512;
    memset(dpp->samplesA, 0, sizeof(dpp->samplesA));
    memset(dpp->samplesB, 0, sizeof(dpp->samplesB));
    dpp->sumA = 0;
    dpp->sumB = 0;

    // Initialize input data with non-zero values to ensure meaningful computation
    for (int j = 0; j < nb_samples; j++) {
        in_left[j] = (j & 1) ? (j * 7) : -(j * 11);
        in_right[j] = (j & 1) ? (j * 13) : -(j * 17);
    }

    // Initialize first sample in samplesA[0] to match loop's use before assignment
    dpp->samplesA[0] = in_left[0];

    // Ensure outputs are zero-initialized
    memset(out_left, 0, nb_samples * sizeof(int32_t));
    memset(out_right, 0, nb_samples * sizeof(int32_t));
}