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
    // Variant 2: Consecutive access using pointer arithmetic for better locality
    double *hx = h->xrange;
    double *h1x = h1->xrange;
    for (i = 0; i <= 107; i++) {
        if (*(h1x + i) != *(hx + i))
            status = 1;
    }
}
