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
    double temp_max = max;
    for (i = 0; i < n; i++) {
        temp_max = (h->bin[i] > temp_max) ? h->bin[i] : temp_max;
    }
    max = temp_max;
}
