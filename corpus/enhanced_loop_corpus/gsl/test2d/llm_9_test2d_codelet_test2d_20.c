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
    size_t limit = 107 * 239;
    for (i = 0; i < limit; i++) {
        double temp = g->bin[i] + 0.25;
        double diff = h1->bin[i] - temp;
        if (diff > 1e-9 || diff < -1e-9)
            status = 1;
    }
}
