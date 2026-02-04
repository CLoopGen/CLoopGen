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
extern gsl_histogram *g;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 794; i += 2) {
        size_t j = i;
        if (j < 397) {
            if (h1->bin[j] != 0.25 + g->bin[j])
                status = 1;
        }
    }
}
