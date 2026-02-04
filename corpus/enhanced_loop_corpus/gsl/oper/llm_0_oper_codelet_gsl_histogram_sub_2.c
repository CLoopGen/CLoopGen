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
extern  gsl_histogram *h2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < h1->n; j++) {
        for (i = j; i < j + 1 && i < h1->n; i++) {
            h1->bin[i] -= h2->bin[i];
        }
    }
}
