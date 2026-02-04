#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern gsl_permutation *dest;
extern  gsl_permutation *src;
extern  size_t src_size;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (src_size > 0) {
        size_t i = 0;
        for (; i < src_size - 1; i += 2) {
            dest->data[i] = src->data[i];
            dest->data[i + 1] = src->data[i + 1];
        }
        if (i < src_size) {
            dest->data[i] = src->data[i];
        }
    }
}
