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
extern int sum;
extern unsigned int scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (m->num_syms <= 0) return;
    m->freqs[0] = (sum * scale) >> 16;
    for (i = 1; i < m->num_syms; i += 2) {
        sum += m->weights[i-1];
        m->freqs[i] = (sum * scale) >> 16;
        if (i+1 < m->num_syms) {
            sum += m->weights[i];
            m->freqs[i+1] = (sum * scale) >> 16;
        }
    }
    if (m->num_syms % 2 == 1) {
        sum += m->weights[m->num_syms - 1];
    }
}
