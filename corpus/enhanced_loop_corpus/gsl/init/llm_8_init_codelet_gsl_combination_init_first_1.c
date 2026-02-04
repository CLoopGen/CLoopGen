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
    // Variant 1: Increased computational intensity with additional arithmetic operations and doubled effective trip count
    // We unroll the loop by a factor of 2 and add arithmetic transformations to increase complexity
    size_t limit = (k + 1) / 2;  // Adjust trip count to handle odd k safely
    for (i = 0; i < limit; i++) {
        c->data[2 * i] = i;
        if (2 * i + 1 < k) {
            c->data[2 * i + 1] = i + k - (k >> 1);  // Introduce non-trivial index computation
        }
    }
}
