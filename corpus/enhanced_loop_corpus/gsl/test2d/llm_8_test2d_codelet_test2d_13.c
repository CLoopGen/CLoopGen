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
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 0; i <= 239; i += step) {
        if (h1->yrange[i] != h->yrange[i]) {
            status = 1;
            break;
        }
        if (i + 1 <= 239 && h1->yrange[i + 1] != h->yrange[i + 1]) {
            status = 1;
            break;
        }
    }
}
