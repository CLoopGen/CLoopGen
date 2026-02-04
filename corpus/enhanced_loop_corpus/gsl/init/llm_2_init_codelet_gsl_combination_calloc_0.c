#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_combination_struct {
    size_t n;
    size_t k;
    size_t *data;
};


typedef struct gsl_combination_struct gsl_combination;

extern  size_t k;
extern size_t i;
extern gsl_combination *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, with bounds check)
    size_t stride = 2;
    for (i = 0; i < k; i += stride) {
        if (i < k) c->data[i] = i;
        size_t j = i + 1;
        if (j < k) c->data[j] = j;
    }
}
