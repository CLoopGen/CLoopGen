#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern size_t n;
extern gsl_histogram *h;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n * 2; i++) {
        size_t idx = i / 2;
        h->bin[idx] = 0;
    }
}
