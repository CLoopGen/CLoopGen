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
    for (size_t outer = 0; outer <= 1; outer++) {
        size_t start = outer * 120;
        size_t end = (outer == 1) ? 239 : 119;
        for (size_t i = start; i <= end; i++) {
            if (h1->yrange[i] != h->yrange[i])
                status = 1;
        }
    }
}
