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

extern gsl_combination *dest;
extern  gsl_combination *src;
extern  size_t src_k;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    size_t j;
    for (j = 0; j < src_k; j += 2) {
        dest->data[j] = src->data[j];
        if (j + 1 < src_k) {
            dest->data[j + 1] = src->data[j + 1];
        }
    }
}
