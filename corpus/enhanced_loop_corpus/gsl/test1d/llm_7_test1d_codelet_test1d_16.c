#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h;
extern size_t i;
extern gsl_histogram *hh;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double diff_range, diff_bin;
    for (i = 0; i < 397; i++) {
        diff_range = h->range[i] - hh->range[i];
        diff_bin = h->bin[i] - hh->bin[i];
        if (diff_range != 0.0)
            status = 1;
        if (diff_bin != 0.0)
            status = 1;
    }
}
