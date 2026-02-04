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



void loop() {
    // Variant 1: Strided memory access (stride of 2) to reduce the number of iterations and change access pattern
    for (j = i + 2; j < size; j += 2) {
        if ((p->data[j] < p->data[i]) && (p->data[j] > p->data[k])) {
            k = j;
        }
        // Handle consecutive element in a fused manner if within bounds
        size_t next = j + 1;
        if (next < size) {
            if ((p->data[next] < p->data[i]) && (p->data[next] > p->data[k])) {
                k = next;
            }
        }
    }
}
