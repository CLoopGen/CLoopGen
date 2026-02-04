#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern gsl_permutation *inv;
extern  gsl_permutation *p;
extern  size_t size;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < size; i++) {
        size_t temp = p->data[i];
        inv->data[temp] = i;
    }
}
