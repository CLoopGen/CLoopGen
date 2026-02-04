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
    size_t prev_i = 0;
    for (i = 1; i < 397; i++) {
        if (h1->bin[prev_i] != g->bin[prev_i] + h->bin[prev_i])
            status = 1;
        prev_i = i;
    }
    // Handle last iteration
    if (h1->bin[prev_i] != g->bin[prev_i] + h->bin[prev_i])
        status = 1;
}
