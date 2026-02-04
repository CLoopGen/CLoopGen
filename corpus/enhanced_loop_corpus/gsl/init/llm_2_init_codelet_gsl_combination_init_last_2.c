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

extern gsl_combination *c;
extern  size_t k;
extern size_t i;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, wrapping around using modulo)
    // This modifies the access pattern to write every second element first, then fill in gaps
    size_t stride = 2;
    for (i = 0; i < k; i++) {
        size_t idx = (i * stride) % k; // strided index with wrap-around
        c->data[idx] = n - k + idx;
    }
}
