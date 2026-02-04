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
for (i = 0; i < 397; i++) {
    status |= (h->range[i] != hh->range[i]) ? 1 : 0;
    status |= (h->bin[i] != hh->bin[i]) ? 1 : 0;
}
}
