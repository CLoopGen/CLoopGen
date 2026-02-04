#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern  size_t size;
extern  gsl_permutation *p;
extern size_t i;
extern size_t k;
extern size_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2, unrolled to handle even and odd indices
    // This changes the access pattern from sequential to strided (every 2nd element)
    count = 0;
    size_t *data = p->data;

    // Process even indices first using stride of 2
    for (i = 0; i < size; i += 2) {
        k = data[i];
        // Replace while loop with iterative conditional updates up to a fixed depth to avoid loops
        for (size_t depth = 0; depth < 4 && k > i; ++depth) {
            if (k < size) {
                k = data[k];
            }
        }
        if (k <= i) {
            count++;
        }
    }

    // Process odd indices separately to maintain strided access
    for (i = 1; i < size; i += 2) {
        k = data[i];
        for (size_t depth = 0; depth < 4 && k > i; ++depth) {
            if (k < size) {
                k = data[k];
            }
        }
        if (k <= i) {
            count++;
        }
    }
}
