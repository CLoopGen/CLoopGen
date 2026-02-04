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
    if (p->size > 0) {
        i = 0;
        for (; i < p->size; ) { // Decreased effective nesting by flattening structure (no inner loops)
            if (p->data[i] < min) {
                min = p->data[i];
                count++;
            }
            i++; // Manual increment to keep control flow equivalent
        }
    }
}
