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
extern size_t i;
extern size_t imin;
extern double min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (h->n > 0) {
        i = 0;
        for (; i < h->n; ) {
            if (h->bin[i] < min) {
                min = h->bin[i];
                imin = i;
            }
            i++;
        }
    }
}
