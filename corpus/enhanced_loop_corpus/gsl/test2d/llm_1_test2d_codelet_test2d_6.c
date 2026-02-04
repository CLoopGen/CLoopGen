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

extern double yr[6];
extern gsl_histogram2d *hr;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 5; i += 2) {
        for (size_t offset = 0; offset <= 1 && (i + offset) <= 5; offset++) {
            size_t idx = i + offset;
            if (hr->yrange[idx] != yr[idx]) {
                status = 1;
            }
        }
    }
}
