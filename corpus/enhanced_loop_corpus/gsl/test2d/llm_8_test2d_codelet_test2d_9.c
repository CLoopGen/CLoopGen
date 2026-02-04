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
extern size_t i;
extern size_t j;
extern size_t k;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 107; i++) {
    for (j = 0; j < 239; j++) {
        k += 2;
        if (h->bin[i * 239 + j] != (double)k || h->bin[i * 239 + j] == 0.0) {
            status = 1;
        }
        k--;
    }
}
}
