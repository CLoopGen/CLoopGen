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
extern  size_t size;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *data = p->data;
    size_t limit = (size + i) / 2;
    for (j = i + 1; j <= limit; j++) {
        size_t idx1 = j;
        size_t idx2 = size + i - j;
        size_t tmp = data[idx1];
        data[idx1] = data[idx2];
        data[idx2] = tmp;
    }
}
