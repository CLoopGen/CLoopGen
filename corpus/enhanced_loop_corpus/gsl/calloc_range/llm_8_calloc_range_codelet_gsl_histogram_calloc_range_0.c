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
extern double *range;
extern size_t i;
extern gsl_histogram *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= n; i += 2) {
        if (i <= n) {
            h->range[i] = range[i] * 2.0;
        }
        if (i + 1 <= n) {
            h->range[i + 1] = range[i + 1] * 2.0;
        }
    }
}
