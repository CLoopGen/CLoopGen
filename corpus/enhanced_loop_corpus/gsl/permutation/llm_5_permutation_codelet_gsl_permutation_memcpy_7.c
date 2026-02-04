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
    for (j = 0; j < src_size; j++) {
        dest->data[j] = src->data[j];
        if (j == src_size - 1) break;
    }
}
