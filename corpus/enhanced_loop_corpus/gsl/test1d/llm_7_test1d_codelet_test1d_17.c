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
    size_t k;
    int local_status = 0;
    for (k = 0; k < 397; k++) {
        if (h->range[k] != hh->range[k])
            local_status = 1;
        if (h->bin[k] != hh->bin[k])
            local_status = 1;
    }
    if (local_status)
        status = 1;
}
