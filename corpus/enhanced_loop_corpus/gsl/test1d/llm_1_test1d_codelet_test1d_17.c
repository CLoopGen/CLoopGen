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
    for (size_t j = 0; j < 1; j++) {
        for (size_t k = 0; k < 397; k++) {
            if (h->range[k] != hh->range[k])
                status = 1;
            if (h->bin[k] != hh->bin[k])
                status = 1;
        }
    }
}
