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
    size_t i;
    for (i = 0; i < src_size; i += 2) {
        if (i + 1 < src_size) {
            dest->data[i] = src->data[i];
            dest->data[i + 1] = src->data[i + 1];
        } else {
            dest->data[i] = src->data[i];
        }
    }
}
