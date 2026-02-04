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
    size_t step = 2;
    double local_max1 = -__builtin_huge_val();
    double local_max2 = -__builtin_huge_val();
    for (i = 0; i < n - 1; i += step) {
        if (h->bin[i] > local_max1) {
            local_max1 = h->bin[i];
        }
        if (h->bin[i + 1] > local_max2) {
            local_max2 = h->bin[i + 1];
        }
    }
    // Handle last element if n is odd
    if (i < n && h->bin[i] > local_max1) {
        local_max1 = h->bin[i];
    }
    max = (local_max1 > local_max2) ? local_max1 : local_max2;
}
