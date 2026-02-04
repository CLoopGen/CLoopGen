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
    m = (Model*)calloc(1, sizeof(Model));
    if (!m) exit(1);

    m->num_syms = 16; // ensures loop runs exactly over the declared array size
    m->tot_weight = 0;
    m->upd_val = 0;
    m->max_upd_val = 0;
    m->till_rescale = 0;

    // Initialize weights to non-zero values to make computation meaningful
    for (int j = 0; j < m->num_syms; j++) {
        m->weights[j] = 1000 + j; // arbitrary initial weights
        m->freqs[j] = j;          // initialize freqs but not used in loop
    }

    i = 0;
}