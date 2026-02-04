#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern  gsl_histogram *h;
extern  size_t n;
extern size_t i;
extern double max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    max = h->bin[0]; // Assume n > 0
    for (i = 1; i < n; i++) {
        if (!(h->bin[i] <= max)) {
            max = h->bin[i];
        }
    }
}
