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
for (i = 0; i < m->num_syms; i++) {
    int temp = m->weights[i];
    if (temp <= m->max_upd_val) {
        temp = (temp + 1) >> 1;
        m->weights[i] = temp;
        m->tot_weight += temp;
    } else {
        m->weights[i] = temp;
    }
}
}
