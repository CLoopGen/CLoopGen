#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *dest;
extern  gsl_histogram *src;
extern size_t n;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *dest_range = dest->range;
    double *src_range = src->range;
    size_t idx = 0;
    if (n == 0) {
        dest_range[0] = src_range[0];
        return;
    }
    while (idx < n) {
        dest_range[idx] = src_range[idx];
        dest_range[idx + 1] = src_range[idx + 1];
        idx += 2;
    }
    if (idx == n) {
        dest_range[n] = src_range[n];
    }
}
