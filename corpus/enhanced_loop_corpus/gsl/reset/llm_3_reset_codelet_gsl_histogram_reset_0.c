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
    // Variant 2: Consecutive write with reverse traversal
    for (i = n; i-- > 0; ) {
        h->bin[i] = 0;
    }
}
