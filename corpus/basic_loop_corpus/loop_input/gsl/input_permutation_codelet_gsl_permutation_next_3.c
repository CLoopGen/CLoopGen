#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};

typedef struct gsl_permutation_struct gsl_permutation;

gsl_permutation *p;
size_t size;
size_t i;
size_t j;

void init_vars() {
    size = 131072; // 128K elements to target ~0.01 sec runtime
    i = size / 4;  // Ensure valid range for i and j

    p = (gsl_permutation *)malloc(sizeof(gsl_permutation));
    if (!p) exit(1);

    p->size = size;
    p->data = (size_t *)malloc(size * sizeof(size_t));
    if (!p->data) exit(1);

    // Initialize data with non-zero values for meaningful swapping
    for (size_t idx = 0; idx < size; ++idx) {
        p->data[idx] = idx + 1;
    }
}