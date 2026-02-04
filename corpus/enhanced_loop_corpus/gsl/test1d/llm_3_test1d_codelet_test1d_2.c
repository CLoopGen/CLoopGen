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
extern gsl_histogram *g;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Traverse arrays from the last element down to the first
    for (i = 396; ; i--) {
        h->bin[i] = i + 27;
        g->bin[i] = (i + 27) * (i + 1);
        if (i == 0) break;
    }
}
