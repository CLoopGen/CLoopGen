#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern  gsl_histogram *src;
extern size_t n;
extern size_t i;
extern gsl_histogram *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < n; outer++) {
        for (size_t inner = 0; inner < 1; inner++) {
            h->bin[outer] = src->bin[outer];
        }
    }
}
