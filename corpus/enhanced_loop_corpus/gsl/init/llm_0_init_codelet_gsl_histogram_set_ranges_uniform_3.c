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
    for (size_t j = 0; j < n; j++) {
        for (i = 0; i < 1; i++) {
            h->bin[j] = 0;
        }
    }
}
