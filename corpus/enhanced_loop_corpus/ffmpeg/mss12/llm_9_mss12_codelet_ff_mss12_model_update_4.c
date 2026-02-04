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
    int limit = (val > m->num_syms) ? m->num_syms : val;
    for (i = limit; i > 0 && m->weights[i - 1] == m->weights[limit]; i -= 2) {
        if (i - 2 >= 0 && m->weights[i - 2] != m->weights[limit]) {
            i--; 
            break;
        }
    }
}
