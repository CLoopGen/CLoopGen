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
extern size_t i;
extern gsl_histogram *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < n; i += 2) {
        h->bin[i] = 0;
        if (i + 1 < n) {
            h->bin[i + 1] = 0;
        }
    }
}
