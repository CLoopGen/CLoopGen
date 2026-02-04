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
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled swap operations
    // Trip count remains similar but each iteration performs more operations via manual unrolling
    for (j = i + 1; j <= ((size + i) / 2); j += 2) {
        // Unroll two iterations when possible
        size_t idx1 = j;
        size_t idx2 = size + i - j;

        size_t tmp1 = p->data[idx1];
        p->data[idx1] = p->data[idx2];
        p->data[idx2] = tmp1;

        if (j + 1 <= ((size + i) / 2)) {
            size_t idx3 = j + 1;
            size_t idx4 = size + i - (j + 1);

            size_t tmp2 = p->data[idx3];
            p->data[idx3] = p->data[idx4];
            p->data[idx4] = tmp2;
        }
    }
}
