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
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with stride increase and simplified inner condition
    // Loop runs fewer iterations by stepping more than one per cycle
    for (j = i + 2; j < size; j += 2) {  // Half the iterations approximately
        // Combine conditions into a single expression to reduce branching overhead
        k = ((p->data[j] > p->data[i]) && (p->data[j] < p->data[k])) ? j : k;
        
        // Optional second check in same iteration if within bounds (unrolled-like behavior)
        if (j + 1 < size) {
            k = ((p->data[j + 1] > p->data[i]) && (p->data[j + 1] < p->data[k])) ? (j + 1) : k;
        }
    }
}
