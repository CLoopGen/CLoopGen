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
    size_t j;
    for (i = 0; i < 397; i++) {
        j = i + 1;
        if (j < 397) {
            if (h->range[i] != hh->range[j])
                status = 1;
            if (h->bin[i] != hh->bin[j])
                status = 1;
        }
    }
}
