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
for (i = 0; i <= 5; i++) {
    if (hr->yrange[i] != yr[i]) {
        status = 1;
    }
}

}
