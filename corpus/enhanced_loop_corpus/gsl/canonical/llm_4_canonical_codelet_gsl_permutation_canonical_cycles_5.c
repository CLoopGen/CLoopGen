#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern  gsl_permutation *p;
extern size_t i;
extern size_t count;
extern size_t min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < p->size; i++) {
        size_t val = p->data[i];
        if (val >= min) continue;
        min = val;
        count++;
    }
}
