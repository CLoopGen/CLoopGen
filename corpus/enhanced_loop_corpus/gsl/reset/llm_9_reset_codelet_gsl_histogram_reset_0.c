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
extern  size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < n; i++) {
        h->bin[i] = 0.0;
        for (j = 1; j < 3; j++) {
            if (i >= j) {
                h->bin[i] += h->bin[i - j];
            }
        }
    }
}
