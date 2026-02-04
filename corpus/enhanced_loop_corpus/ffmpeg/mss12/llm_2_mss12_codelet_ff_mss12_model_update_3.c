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
    // Variant 1: Strided memory access (access every 2nd element backward, then cover the rest)
    int start = (val - 1) % 2;
    for (i = val - 1; i >= start; i -= 2) {
        m->cum_prob[i]++;
    }
    start = (val - 2 >= 0) ? 1 : 0;
    for (i = start + ((val - 1 - start) / 2) * 2; i >= 0; i -= 2) {
        if (i != val - 1) { // Avoid duplicate increment
            m->cum_prob[i]++;
        }
    }
}
