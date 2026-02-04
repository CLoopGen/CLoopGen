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

extern Model *m;
extern int i;
extern int cum_prob;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every second element first, then the others)
    int stride = 2;
    for (i = m->num_syms; i >= 0; i -= stride) {
        m->cum_prob[i] = cum_prob;
        m->weights[i] = (m->weights[i] + 1) >> 1;
        cum_prob += m->weights[i];
    }
    // Handle remaining odd index if num_syms is odd
    if ((m->num_syms & 1) == 0) {
        i = m->num_syms - 1;
    } else {
        i = m->num_syms - 1;
    }
    for (; i >= 0; i -= stride) {
        m->cum_prob[i] = cum_prob;
        m->weights[i] = (m->weights[i] + 1) >> 1;
        cum_prob += m->weights[i];
    }
}
