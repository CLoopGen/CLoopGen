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



void loop() {
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    int stride = 2;
    int offset;

    // First pass: even indices
    for (offset = 0; offset < stride; offset++) {
        for (i = offset; i < m->num_syms; i += stride) {
            m->freqs[i] = sum * scale >> 16;
            sum += m->weights[i];
        }
    }
}
