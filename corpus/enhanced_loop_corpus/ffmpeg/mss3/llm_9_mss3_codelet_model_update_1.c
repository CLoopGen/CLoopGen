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
    int factor = (m->upd_val > 8) ? 3 : 1;
    for (i = 0; i < m->num_syms && i < 8; i++) {
        m->weights[i] = (m->weights[i] + factor) >> 1;
        m->freqs[i] += 1;
        m->tot_weight += m->weights[i] * (m->freqs[i] & 1 ? 1 : 2);
    }
    if (m->till_rescale < 4) {
        for (i = 0; i < m->num_syms; i++) {
            m->weights[i] = (m->weights[i] + 1) >> 1;
        }
    }
}
