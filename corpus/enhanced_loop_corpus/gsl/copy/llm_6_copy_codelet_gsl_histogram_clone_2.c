#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern  gsl_histogram *src;
extern size_t n;
extern size_t i;
extern gsl_histogram *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *src_bin = src->bin;
    double *h_bin = h->bin;
    size_t i0, i1, i2, i3;
    for (i = 0; i + 3 < n; i += 4) {
        i0 = i;
        i1 = i + 1;
        i2 = i + 2;
        i3 = i + 3;
        h_bin[i0] = src_bin[i0];
        h_bin[i1] = src_bin[i1];
        h_bin[i2] = src_bin[i2];
        h_bin[i3] = src_bin[i3];
    }
    for (; i < n; i++) {
        h->bin[i] = src->bin[i];
    }
}
