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
extern int val;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_val = val;
    for (i = val; i > 0 && m->weights[i - 1] == m->weights[temp_val]; i--) {
        m->cum_prob[i] = m->cum_prob[i - 1];
    }
}
