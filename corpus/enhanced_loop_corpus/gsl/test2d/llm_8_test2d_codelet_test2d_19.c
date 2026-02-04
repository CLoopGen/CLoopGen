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
    // Variant 1: Increased computational intensity with additional arithmetic and reduced trip count
    for (i = 0; i < 107 * 239 / 2; i += 2) {
        double val_h1 = h1->bin[i];
        double val_g = g->bin[i];
        double computed = 0.5 * val_g + 0.1 * val_h1 * val_g;
        if (val_h1 > computed || val_h1 < (computed - 0.01))
            status = 1;
    }
}
