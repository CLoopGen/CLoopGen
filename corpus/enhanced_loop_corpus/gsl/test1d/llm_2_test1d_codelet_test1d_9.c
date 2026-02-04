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
extern gsl_histogram *h1;
extern gsl_histogram *g;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 4 (unrolled-like pattern)
    for (i = 0; i < 397; i += 4) {
        // Check four elements per iteration with bounds checking
        if (i + 0 < 397 && h1->bin[i + 0] != g->bin[i + 0] + h->bin[i + 0])
            status = 1;
        if (i + 1 < 397 && h1->bin[i + 1] != g->bin[i + 1] + h->bin[i + 1])
            status = 1;
        if (i + 2 < 397 && h1->bin[i + 2] != g->bin[i + 2] + h->bin[i + 2])
            status = 1;
        if (i + 3 < 397 && h1->bin[i + 3] != g->bin[i + 3] + h->bin[i + 3])
            status = 1;
    }
}
