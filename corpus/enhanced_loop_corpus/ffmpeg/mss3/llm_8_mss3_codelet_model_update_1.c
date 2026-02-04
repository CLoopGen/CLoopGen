#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Model {
    int weights[16];
    int freqs[16];
    int num_syms;
    int tot_weight;
    int upd_val;
    int max_upd_val;
    int till_rescale;
} Model;

extern Model *m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < m->num_syms; i += 2) {
        if (i + 1 < m->num_syms) {
            m->weights[i]     = (m->weights[i]     + 2) >> 2;
            m->weights[i + 1] = (m->weights[i + 1] + 2) >> 2;
            m->tot_weight += m->weights[i] + m->weights[i + 1];
        } else {
            m->weights[i] = (m->weights[i] + 2) >> 2;
            m->tot_weight += m->weights[i];
        }
    }
}
