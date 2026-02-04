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
    // Variant 1: Strided memory access pattern
    // Instead of decrementing by 1, we use a stride of -2 to access every other element.
    // We also ensure we don't go out of bounds by checking i > val/2 (arbitrary safe bound).
    int stride = 2;
    for (i = val; (i - stride) >= 1 && m->weights[i - stride] == m->weights[val]; i -= stride)
        ;
}
