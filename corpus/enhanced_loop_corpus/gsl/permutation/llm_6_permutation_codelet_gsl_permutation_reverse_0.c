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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *data = p->data;
    size_t n = size;
    for (i = 0; i < (n / 2); i++) {
        size_t j = n - i - 1;
        size_t tmp1 = data[i];
        size_t tmp2 = data[j];
        data[i] = tmp2;
        data[j] = tmp1;
    }
}
