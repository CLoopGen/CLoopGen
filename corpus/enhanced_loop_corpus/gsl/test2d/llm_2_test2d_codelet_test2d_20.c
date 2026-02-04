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
    size_t stride = 2;
    for (i = 0; i < 107 * 239; i += stride) {
        if (h1->bin[i] != 0.25 + g->bin[i])
            status = 1;
        if (i + 1 < 107 * 239 && h1->bin[i + 1] != 0.25 + g->bin[i + 1])
            status = 1;
    }
}
