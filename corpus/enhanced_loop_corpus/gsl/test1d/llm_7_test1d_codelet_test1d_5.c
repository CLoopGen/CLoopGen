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
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t prev_i = 0;
    for (i = 0; i < 397; i++) {
        if (h->bin[i] != (double)(prev_i + 1)) {
            status = 1;
        }
        prev_i = i;
    }
}
