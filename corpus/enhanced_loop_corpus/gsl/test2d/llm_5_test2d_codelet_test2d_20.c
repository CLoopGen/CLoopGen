#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

extern gsl_histogram2d *h1;
extern gsl_histogram2d *g;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    size_t end = 107 * 239;
    for (j = 0; j < end; j++) {
        if (h1->bin[j] == 0.25 + g->bin[j]) continue;
        status = 1;
        break;
    }
}
