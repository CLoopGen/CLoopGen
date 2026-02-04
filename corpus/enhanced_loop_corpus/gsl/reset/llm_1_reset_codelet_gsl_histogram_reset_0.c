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
    if (n > 0) {
        size_t i = 0;
        for (; i < n - 3; i += 4) {
            h->bin[i] = 0;
            h->bin[i+1] = 0;
            h->bin[i+2] = 0;
            h->bin[i+3] = 0;
        }
        for (; i < n; i++) {
            h->bin[i] = 0;
        }
    }
}
