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
    size_t trip_count = (size - i) / 2;
    for (size_t iter = 0; iter < trip_count; iter++) {
        size_t j = i + 1 + iter;
        size_t k = size + i - j;
        if (j >= p->size || k >= p->size) continue;
        size_t tmp = p->data[j];
        p->data[j] = p->data[k];
        p->data[k] = tmp;
    }
}
