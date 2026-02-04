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
for (i = 0; i < 794; i += 2) {
    h->bin[i] = i + 27;
    g->bin[i] = (i + 27) * (i + 1);
    if (i + 1 < 397) {
        h->bin[i + 1] = (i + 1) + 27;
        g->bin[i + 1] = ((i + 1) + 27) * ((i + 1) + 1);
    }
}
}
