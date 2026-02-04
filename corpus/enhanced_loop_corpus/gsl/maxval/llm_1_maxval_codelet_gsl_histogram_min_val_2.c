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
extern double min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (h->n > 0) {
        for (i = 0; i < h->n; i += 2) {
            if (h->bin[i] < min) {
                min = h->bin[i];
            }
            if (i + 1 < h->n && h->bin[i + 1] < min) {
                min = h->bin[i + 1];
            }
        }
    }
}
