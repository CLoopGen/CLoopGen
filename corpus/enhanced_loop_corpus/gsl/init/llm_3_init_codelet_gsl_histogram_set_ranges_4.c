#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h;
extern  double range[];
extern size_t i;
extern  size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access – traverse from high to low index
    size_t i;
    for (i = n; i != (size_t)-1; i--) {
        h->range[i] = range[i];
    }
}
