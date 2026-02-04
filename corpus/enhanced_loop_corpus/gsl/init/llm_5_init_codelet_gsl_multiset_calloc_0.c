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

extern  size_t k;
extern size_t i;
extern gsl_multiset *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < k; i++) {
        c->data[i] = 0;
        if (c->data[i] != 0) {
            c->data[i] = 0;
        }
    }
}
