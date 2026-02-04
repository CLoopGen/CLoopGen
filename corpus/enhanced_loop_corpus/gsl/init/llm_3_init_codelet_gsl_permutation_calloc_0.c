#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern  size_t n;
extern size_t i;
extern gsl_permutation *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using reverse index mapping
    for (i = 0; i < n; i++) {
        size_t rev_index = n - 1 - i;  // Reverse the access order
        p->data[rev_index] = rev_index;
    }
}
