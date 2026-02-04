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
    size_t j;
    status = 0;
    for (i = 0; i < 397; i++) {
        j = i + 1;
        if (j < 397 && h->bin[i] != 0) {
            status = 1;
        }
    }
}
