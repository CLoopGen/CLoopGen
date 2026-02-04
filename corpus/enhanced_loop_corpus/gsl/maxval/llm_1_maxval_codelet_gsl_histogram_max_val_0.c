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
    if (n > 0) {
        for (i = 0; i < n; i += 2) {
            if (h->bin[i] > max) {
                max = h->bin[i];
            }
            if (i + 1 < n && h->bin[i + 1] > max) {
                max = h->bin[i + 1];
            }
        }
    }
}
