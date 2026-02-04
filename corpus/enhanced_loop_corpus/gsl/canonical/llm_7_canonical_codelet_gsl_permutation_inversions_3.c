#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern  gsl_permutation *p;
extern size_t count;
extern size_t i;
extern size_t j;
extern  size_t size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size == 0) return;
    // Reverse iteration order to change data access pattern and eliminate loop-carried dependency on forward indices
    for (i = size - 2; i != SIZE_MAX; i--) { // i wraps around when underflowing, acts like i >= 0
        for (j = size - 1; j > i; j--) {
            // Maintain same comparison but reverse traversal introduces different RAW dependency chain
            // Each iteration now depends on higher indices first, changing memory access locality
            if (p->data[i] > p->data[j]) {
                count++;
            }
        }
    }
}
