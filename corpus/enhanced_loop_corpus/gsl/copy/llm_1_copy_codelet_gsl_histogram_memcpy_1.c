#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *dest;
extern  gsl_histogram *src;
extern size_t n;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        size_t i = 0;
        for (; i < n - 3; i += 4) {
            dest->bin[i]     = src->bin[i];
            dest->bin[i + 1] = src->bin[i + 1];
            dest->bin[i + 2] = src->bin[i + 2];
            dest->bin[i + 3] = src->bin[i + 3];
        }
        for (; i < n; i++) {
            dest->bin[i] = src->bin[i];
        }
    }
}
