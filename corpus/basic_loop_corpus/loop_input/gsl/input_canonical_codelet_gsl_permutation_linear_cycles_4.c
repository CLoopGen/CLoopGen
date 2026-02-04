#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};

typedef struct gsl_permutation_struct gsl_permutation;

size_t size = 1000000;
gsl_permutation *p;
size_t i;
size_t k;
size_t count;

void init_vars() {
    p = (gsl_permutation*)malloc(sizeof(gsl_permutation));
    p->size = size;
    p->data = (size_t*)malloc(size * sizeof(size_t));

    for (size_t idx = 0; idx < size; idx++) {
        if (idx == 0) {
            p->data[idx] = 0;
        } else {
            // Create a structure where each element points to a smaller index or itself
            // This ensures termination of the while loop and keeps k >= 0
            p->data[idx] = rand() % (idx + 1);
        }
    }

    i = 0;
    k = 0;
    count = 0;
}