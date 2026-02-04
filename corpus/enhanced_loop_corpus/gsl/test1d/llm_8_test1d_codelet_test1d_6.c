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
extern gsl_histogram *h1;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 397; i += 2) {
        if (h1->range[i] != h->range[i] || h1->range[i+1] != h->range[i+1])
            status = 1;
    }
}
