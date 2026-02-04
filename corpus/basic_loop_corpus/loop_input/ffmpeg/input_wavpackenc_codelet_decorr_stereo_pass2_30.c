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

static struct Decorr decorr_instance;

struct Decorr *dpp = &decorr_instance;
int32_t *samples_l;
int32_t *samples_r;
int nb_samples;
int i;

void init_vars() {
    nb_samples = 2097152; // ~8MB per array (2M * 4 bytes), total data ~16MB, loop should run around 0.01-0.1s

    samples_l = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));
    samples_r = (int32_t*)aligned_alloc(32, nb_samples * sizeof(int32_t));

    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = (j * 7919) % 65536; 
        samples_r[j] = (j * 12345) % 65536;
    }

    dpp->delta = 16;
    dpp->weightA = 512;
    dpp->weightB = 512;
    dpp->value = 0;
    dpp->sumA = 0;
    dpp->sumB = 0;

    for (int k = 0; k < 8; k++) {
        dpp->samplesA[k] = (k + 1) * 1000;
        dpp->samplesB[k] = (k + 1) * 1000;
    }
}