#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_combination_struct {
    size_t n;
    size_t k;
    size_t *data;
};


typedef struct gsl_combination_struct gsl_combination;

extern gsl_combination *c;
extern  size_t k;
extern size_t i;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access – traverse the array from last to first
    // Maintains sequential access but in reverse order, altering spatial locality
    for (i = k; i > 0; --i) {
        size_t idx = i - 1;
        c->data[idx] = n - k + idx;
    }
}
