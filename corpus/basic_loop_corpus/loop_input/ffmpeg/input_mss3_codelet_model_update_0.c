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
int sum;
unsigned int scale;

void init_vars() {
    m = (Model*)calloc(1, sizeof(Model));
    if (!m) {
        exit(1);
    }

    m->num_syms = 16;
    m->tot_weight = 0;
    m->upd_val = 1;
    m->max_upd_val = 100;
    m->till_rescale = 50;

    for (int idx = 0; idx < 16; idx++) {
        m->weights[idx] = (idx + 1) * 1000;
    }

    sum = 1 << 16;
    scale = 1 << 16;
}