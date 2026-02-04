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
    size_t j;
    double temp[397];
    for (j = 0; j < 397; j++) {
        temp[j] = g->bin[j] * h->bin[j];
    }
    for (j = 0; j < 397; j++) {
        if (h1->bin[j] != temp[j])
            status = 1;
    }
}
