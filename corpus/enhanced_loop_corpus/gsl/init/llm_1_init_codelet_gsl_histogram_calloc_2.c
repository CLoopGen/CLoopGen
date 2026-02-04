#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern size_t n;
extern gsl_histogram *h;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        i = 0;
        for (size_t outer = 0; outer < 1; outer++) {
            for (; i < n; i++) {
                h->bin[i] = 0;
            }
        }
    }
}
