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
for (i = 0; i < 397; i += 4) {
    for (size_t j = 0; j < 4 && (i + j) < 397; j++) {
        size_t idx = i + j;
        if (h->range[idx] != hh->range[idx])
            status = 1;
        if (h->bin[idx] != hh->bin[idx])
            status = 1;
    }
}
}
