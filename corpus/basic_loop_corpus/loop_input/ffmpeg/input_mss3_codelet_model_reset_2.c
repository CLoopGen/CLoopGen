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

Model *m;
int i;

void init_vars() {
    m = (Model*)malloc(sizeof(Model));
    if (!m) exit(1);

    m->num_syms = 16;  
    m->tot_weight = 0;
    m->upd_val = 0;
    m->max_upd_val = 100;
    m->till_rescale = 50;

    for (int j = 0; j < 16; j++) {
        m->weights[j] = 0;
        m->freqs[j] = j + 1;
    }
}