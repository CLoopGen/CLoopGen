#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Model {
    int16_t cum_prob[257];
    int16_t weights[257];
    uint8_t idx2sym[257];
    int num_syms;
    int thr_weight;
    int threshold;
} Model;

Model *m;
int i;

void init_vars() {
    m = (Model*)malloc(sizeof(Model));
    if (!m) {
        exit(1);
    }
    m->num_syms = 256;
    m->thr_weight = 100;
    m->threshold = 50;
    for (int j = 0; j < 257; j++) {
        m->idx2sym[j] = (uint8_t)(j & 0xFF);
    }
}

// The loop function will be provided externally