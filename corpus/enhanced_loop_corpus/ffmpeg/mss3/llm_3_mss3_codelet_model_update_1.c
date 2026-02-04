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



void loop() {
    // Variant 2: Reverse consecutive memory access
    int n = m->num_syms;
    
    // Traverse the array from last to first
    for (i = n - 1; i >= 0; i--) {
        m->weights[i] = (m->weights[i] + 1) >> 1;
        m->tot_weight += m->weights[i];
    }
}
