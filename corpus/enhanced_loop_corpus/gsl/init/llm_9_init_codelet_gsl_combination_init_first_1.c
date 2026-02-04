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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with higher arithmetic density per iteration
    // Process elements in reverse and apply cumulative arithmetic pattern
    for (i = 0; i < (k + 3) / 4; i++) {  // Reduce number of iterations significantly
        size_t idx1 = k - 1 - i;
        size_t idx2 = k - 1 - (i + k/2) % k;
        c->data[idx1] = (i * i + 2*i + 1) % k;  // Quadratic expression
        if (idx1 != idx2 && idx2 < k) {
            c->data[idx2] = (i * (i + 1)) / 2;  // Triangular number
        }
    }
}
