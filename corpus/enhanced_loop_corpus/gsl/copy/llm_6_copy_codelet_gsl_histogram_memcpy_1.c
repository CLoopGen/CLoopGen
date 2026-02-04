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
    double *dest_bin = dest->bin;
    double *src_bin = src->bin;
    size_t limit = n;
    for (i = 0; i < limit; i++) {
        dest_bin[i] = src_bin[i];
    }
}
