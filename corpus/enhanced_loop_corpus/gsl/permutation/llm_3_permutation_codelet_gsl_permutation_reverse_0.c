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
    // Variant 2: Indirect memory access using an index remapping array (simulated via arithmetic)
    // Instead of direct i and j, use a precomputed reverse index pattern applied indirectly
    for (i = 0; i < (size / 2); i++) {
        size_t forward_idx = i;
        size_t reverse_idx = size - i - 1;

        size_t tmp = p->data[forward_idx];
        p->data[forward_idx] = p->data[reverse_idx];
        p->data[reverse_idx] = tmp;
    }
}
