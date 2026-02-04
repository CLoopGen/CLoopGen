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
    status = 0;
    for (j = 0; j < 107 * 239; j += 2) {
        if (j + 1 < 107 * 239) {
            if (h1->bin[j] != 0.5 * g->bin[j])
                status = 1;
            if (h1->bin[j + 1] != 0.5 * g->bin[j + 1])
                status = 1;
        } else {
            if (h1->bin[j] != 0.5 * g->bin[j])
                status = 1;
        }
    }
}
