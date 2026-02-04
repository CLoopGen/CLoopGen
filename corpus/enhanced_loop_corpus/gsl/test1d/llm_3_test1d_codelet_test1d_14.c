#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h1;
extern gsl_histogram *g;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access pattern
    // Traverse the array from the end to the beginning using descending index
    for (i = 396; i != (size_t)-1; i--) {
        if (h1->bin[i] != 0.25 + g->bin[i])
            status = 1;
    }
}
