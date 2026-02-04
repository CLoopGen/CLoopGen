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
    double prev = 0.0;
    for (i = 0; i < 397; i++) {
        double computed = g->bin[i] / h->bin[i] + prev;
        if (h1->bin[i] != computed - prev)
            status = 1;
        prev = computed;
    }
}
