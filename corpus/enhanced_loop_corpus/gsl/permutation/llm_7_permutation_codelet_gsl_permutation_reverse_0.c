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
    size_t offset = 0;
    for (i = 0; i < (n / 2); i++) {
        size_t j = n - i - 1;
        size_t tmp = data[i + offset];
        data[i + offset] = data[j];
        data[j] = tmp;
        offset = (offset == 0) ? 0 : 0; // Redundant assignment to maintain WAW dependency without altering behavior
    }
}
