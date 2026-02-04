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

extern gsl_multiset *c;
extern  size_t k;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *data_ptr = c->data;
    for (i = 0; i < k; i++) {
        *(data_ptr + i) = 0;
    }
}
