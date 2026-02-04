#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern  size_t n;
extern size_t i;
extern gsl_permutation *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp;
    for (i = 0; i < n; i++) {
        temp = i;
        p->data[i] = temp;
    }
}
