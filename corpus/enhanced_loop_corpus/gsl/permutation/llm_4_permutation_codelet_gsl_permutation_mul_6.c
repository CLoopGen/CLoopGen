#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern gsl_permutation *p;
extern  gsl_permutation *pa;
extern  gsl_permutation *pb;
extern size_t i;
extern  size_t size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        if (pa->data[i] < pb->size) {
            p->data[i] = pb->data[pa->data[i]];
        } else {
            p->data[i] = 0;
        }
    }
}
