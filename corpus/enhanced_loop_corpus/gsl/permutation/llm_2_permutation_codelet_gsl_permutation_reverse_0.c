#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern gsl_permutation *p;
extern  size_t size;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (process pairs of elements from both ends)
    for (i = 0; i < (size / 2); i += 2) {
        size_t j1 = size - i - 1;
        size_t j2 = size - (i + 1) - 1;

        size_t tmp1 = p->data[i];
        p->data[i] = p->data[j1];
        p->data[j1] = tmp1;

        if (i + 1 < (size / 2)) { // Avoid out-of-bounds when size is odd
            size_t tmp2 = p->data[i + 1];
            p->data[i + 1] = p->data[j2];
            p->data[j2] = tmp2;
        }
    }
}
