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
double prev_h = 0.0;
for (i = 0; i < 397; i++) {
    h->bin[i] = prev_h + i + 27;
    g->bin[i] = (i + 27) * (i + 1);
    prev_h = h->bin[i];
}
}
