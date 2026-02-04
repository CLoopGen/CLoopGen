#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_multiset_struct {
    size_t n;
    size_t k;
    size_t *data;
};


typedef struct gsl_multiset_struct gsl_multiset;

extern gsl_multiset *dest;
extern  gsl_multiset *src;
extern  size_t src_k;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *dest_data = dest->data;
    size_t *src_data = src->data;
    for (j = 0; j < src_k; j++) {
        *(dest_data + j) = *(src_data + j);
    }
}
