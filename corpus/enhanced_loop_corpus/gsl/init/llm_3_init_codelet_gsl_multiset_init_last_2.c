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
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = k; i > 0; i--) {
        c->data[i - 1] = n - 1;
    }
}
