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
    double *bin_ptr = h->bin;
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            bin_ptr[i] = 0;
            bin_ptr[i + 1] = 0; // Remove potential WAW dependency by unrolling and writing independent elements
        } else {
            bin_ptr[i] = 0;
        }
    }
}
