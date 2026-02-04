#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Model {
    int16_t cum_prob[257];
    int16_t weights[257];
    uint8_t idx2sym[257];
    int num_syms;
    int thr_weight;
    int threshold;
} Model;

extern Model *m;
extern int val;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via index remapping using idx2sym as an indirection vector
    // Here, we use the idx2sym array to indirectly compare weight values.
    // We treat idx2sym as a permutation map and access weights through it.
    // Loop condition now compares weights indirectly: weights[idx2sym[i-1]] vs weights[idx2sym[val]]
    // This creates a non-linear, data-dependent access pattern.
    for (i = val; 
         (i - 1) >= 0 && m->idx2sym[i - 1] < m->num_syms && m->idx2sym[val] < m->num_syms &&
         m->weights[m->idx2sym[i - 1]] == m->weights[m->idx2sym[val]]; 
         i--)
        ;
}
