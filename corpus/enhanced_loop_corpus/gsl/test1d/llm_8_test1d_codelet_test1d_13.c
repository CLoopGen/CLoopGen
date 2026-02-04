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
    for (i = 0; i < 794; i += 2) {
        size_t j = i + 1;
        if (j < 397 && h1->bin[j] != 0.5 * g->bin[j])
            status = 1;
        if (i < 397 && h1->bin[i] != 0.5 * g->bin[i])
            status = 1;
    }
}
