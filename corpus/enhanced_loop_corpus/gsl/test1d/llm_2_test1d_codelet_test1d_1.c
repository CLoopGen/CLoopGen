#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 397; i += 2) {
        h1->range[i] = 100. + i;
        if (i + 1 <= 397) {
            h1->range[i + 1] = 100. + (i + 1);
        }
    }
}
