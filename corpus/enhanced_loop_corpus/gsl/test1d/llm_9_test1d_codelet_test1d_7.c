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
extern gsl_histogram *h1;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = 398;
    for (i = 0; i < limit; i++) {
        double diff = h1->range[i] - h->range[i];
        if (diff > 1e-9 || diff < -1e-9) {
            status = 1;
            break;
        }
        if (i % 4 == 0) {
            asm volatile("" ::: "memory"); // Artificial computational load
        }
    }
}
