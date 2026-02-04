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
    size_t j;
    for (j = 0; j < size; j += 2) {
        if (j + 1 < size) {
            p->data[j] = pb->data[pa->data[j]];
            p->data[j+1] = pb->data[pa->data[j+1]];
        } else {
            p->data[j] = pb->data[pa->data[j]];
        }
    }
}
