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



void loop(){
    for (i = m->num_syms; i >= 0; i--) {
        cum_prob += m->weights[i];
        m->cum_prob[i] = cum_prob;
        m->weights[i] = (m->weights[i] + 1) >> 1;
        if (cum_prob > m->threshold) break;
    }
}
