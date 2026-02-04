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
    ptrdiff_t stride = 2;
    size_t limit = (k + stride - 1) / stride;
    for (i = 0; i < limit; i++) {
        size_t idx1 = i * stride;
        if (idx1 < k) {
            c->data[idx1] = 0;
        }
        size_t idx2 = i * stride + 1;
        if (idx2 < k) {
            c->data[idx2] = 0;
        }
    }
}
