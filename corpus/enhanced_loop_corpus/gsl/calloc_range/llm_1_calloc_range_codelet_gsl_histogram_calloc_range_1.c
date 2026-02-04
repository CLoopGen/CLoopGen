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
extern size_t i;
extern gsl_histogram *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        for (i = 0; i < n / 2; i++) {
            h->bin[i] = 0;
            h->bin[n - 1 - i] = 0;
        }
        if (n % 2 == 1) {
            h->bin[n / 2] = 0;
        }
    }
}
