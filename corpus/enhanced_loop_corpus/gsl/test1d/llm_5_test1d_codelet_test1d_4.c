#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern double xr[11];
extern gsl_histogram *hr;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    status = 0;
    for (i = 0; i <= 10 && status == 0; i++) {
        if (hr->range[i] != xr[i]) {
            status = 1;
        }
    }
}
