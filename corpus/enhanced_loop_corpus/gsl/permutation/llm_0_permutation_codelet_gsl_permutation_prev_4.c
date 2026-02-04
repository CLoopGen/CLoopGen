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
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = i + 2; j < size; j++) {
        if ((p->data[j] < p->data[i]) && (p->data[j] > p->data[k])) {
            k = j;
        }
        for (size_t extra = 0; extra < 1; extra++) {
            // Artificially increased nesting depth by adding a trivial inner loop
            // Does not alter logic but increases loop depth
        }
    }
}
