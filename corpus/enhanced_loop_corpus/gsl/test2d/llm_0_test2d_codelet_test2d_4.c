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

extern gsl_histogram2d *h;
extern gsl_histogram2d *g;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 107; outer++) {
        for (size_t inner = 0; inner < 239; inner++) {
            size_t i = outer * 239 + inner;
            h->bin[i] = i + 27;
            g->bin[i] = (i + 27) * (i + 1);
        }
    }
}
