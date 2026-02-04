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
    for (size_t outer = 0; outer < n; outer += 16) {
        for (size_t i = outer; i < ((outer + 16) <= n ? (outer + 16) : n); i++) {
            dest->bin[i] = src->bin[i];
        }
    }
}
