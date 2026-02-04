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
    nb_samples = 4194304; // ~16.7 MB of input data (4 bytes * 2 arrays * 4M)
    
    dpp = (struct Decorr *)calloc(1, sizeof(struct Decorr));
    if (!dpp) exit(1);
    
    dpp->delta = 16;
    dpp->weightA = 512;
    dpp->weightB = 512;
    for (int j = 0; j < 8; j++) {
        dpp->samplesA[j] = (j == 0) ? 100 : 0;
        dpp->samplesB[j] = (j == 0) ? 100 : 0;
    }
    dpp->sumA = 0;
    dpp->sumB = 0;

    samples_l = (int32_t *)calloc(nb_samples, sizeof(int32_t));
    samples_r = (int32_t *)calloc(nb_samples, sizeof(int32_t));
    if (!samples_l || !samples_r) exit(1);

    for (int j = 0; j < nb_samples; j++) {
        samples_l[j] = (j % 2) ? 1000 : -1000;
        samples_r[j] = (j % 2) ? -1000 : 1000;
    }
}