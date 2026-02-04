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
    int temp_weights[16];
    for (i = 0; i < m->num_syms - 1; i++)
        temp_weights[i] = 1;
    // Eliminate write-after-write (WAW) on m->weights by using local buffer; no loop-carried dependency
    for (i = 0; i < m->num_syms - 1; i++)
        m->weights[i] = temp_weights[i];
}
