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



void loop(){
    size_t *data = p->data;
    count = 0;
    for (i = 0; i < size; i++) {
        k = data[i];
        for (; k > i; ) {
            k = data[k];
        }
        if (k >= i) {
            count++;
        }
    }
}
