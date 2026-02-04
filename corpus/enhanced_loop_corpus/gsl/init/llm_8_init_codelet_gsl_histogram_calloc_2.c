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
    size_t step = 2;
    for (i = 0; i < n; i += step) {
        if (i + 1 < n) {
            h->bin[i] = 0;
            h->bin[i + 1] = 0;
        } else {
            h->bin[i] = 0;
        }
    }
}
