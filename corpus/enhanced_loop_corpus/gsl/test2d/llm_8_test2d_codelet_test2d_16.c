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
extern gsl_histogram2d *h1;
extern gsl_histogram2d *g;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = 107 * 239;
    for (i = 0; i < limit; i += 2) {
        if (i + 1 < limit) {
            double diff1 = g->bin[i] - h->bin[i];
            double diff2 = g->bin[i+1] - h->bin[i+1];
            if (h1->bin[i] != diff1 || h1->bin[i+1] != diff2)
                status = 1;
        } else {
            if (h1->bin[i] != g->bin[i] - h->bin[i])
                status = 1;
        }
    }
}
