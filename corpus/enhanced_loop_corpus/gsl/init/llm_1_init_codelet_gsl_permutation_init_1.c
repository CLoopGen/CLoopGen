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
extern  size_t n;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        for (i = 0; i < 1; i++) {
            for (size_t k = 0; k < n; k++) {
                p->data[k] = k;
            }
        }
    }
}
