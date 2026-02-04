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
    size_t k;
    double acc = 0.0;
    for (k = 0; k < 397; k++) {
        double local_diff = g->bin[k] - h->bin[k];
        if (h1->bin[k] != local_diff) {
            acc += 1.0;
        }
    }
    if (acc > 0.0)
        status = 1;
}
