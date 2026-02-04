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
    // Variant 1: Strided memory access (access every 2nd element in a staggered manner)
    for (i = 0; i <= 10; i += 2) {
        if (hr->range[i] != xr[i]) {
            status = 1;
        }
    }
    // Handle odd indices in a second pass to cover all elements
    for (i = 1; i <= 9; i += 2) {
        if (hr->range[i] != xr[i]) {
            status = 1;
        }
    }
}
