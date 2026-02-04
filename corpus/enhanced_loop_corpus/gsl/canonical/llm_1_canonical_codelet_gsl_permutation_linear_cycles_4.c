#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern  size_t size;
extern  gsl_permutation *p;
extern size_t i;
extern size_t k;
extern size_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < size; i++) {
        for (k = p->data[i]; k > i; k = p->data[k]) {
        }
        if (k < i)
            continue;
        count++;
    }
}
