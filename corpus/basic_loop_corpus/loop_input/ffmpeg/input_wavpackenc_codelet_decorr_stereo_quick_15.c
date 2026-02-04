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

int32_t *in_left;
int32_t *in_right;
int32_t *out_left;
int32_t *out_right;
int nb_samples;
struct Decorr *dpp;
int i;

void init_vars() {
    const size_t data_size = 16777216; // 64 MB of samples (16M * 4 bytes)
    nb_samples = data_size / sizeof(int32_t);

    in_left = aligned_alloc(32, data_size);
    in_right = aligned_alloc(32, data_size);
    out_left = aligned_alloc(32, data_size);
    out_right = aligned_alloc(32, data_size);

    dpp = aligned_alloc(32, sizeof(struct Decorr));
    memset(dpp, 0, sizeof(struct Decorr));

    dpp->delta = 10;
    dpp->weightA = 512;
    dpp->weightB = 512;

    for (int j = 0; j < 8; j++) {
        dpp->samplesA[j] = (j == 0) ? 100 : (j == 1) ? 90 : 0;
        dpp->samplesB[j] = (j == 0) ? 100 : (j == 1) ? 90 : 0;
    }

    for (int j = 0; j < nb_samples; j++) {
        in_left[j] = (int32_t)(j * 7 + 12345);
        in_right[j] = (int32_t)(j * 13 + 67890);
        out_left[j] = 0;
        out_right[j] = 0;
    }
}