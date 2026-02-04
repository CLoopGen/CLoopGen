#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *dest;
extern  gsl_histogram *src;
extern size_t n;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = n; i != (size_t)-1; i--) {
        dest->range[i] = src->range[i];
    }
}
