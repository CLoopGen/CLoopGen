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
int cum_prob;

void init_vars() {
    m = (Model*)malloc(sizeof(Model));
    if (!m) exit(1);

    m->num_syms = 256;
    m->thr_weight = 100;
    m->threshold = 50;

    cum_prob = 0;

    for (int j = 0; j < 257; j++) {
        m->weights[j] = (int16_t)(j * 3);
        m->idx2sym[j] = (uint8_t)(j % 256);
        m->cum_prob[j] = 0;
    }
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}