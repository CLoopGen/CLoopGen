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
    for (i = 0; i < 397; i += 2) {
        if (h->bin[i] != (double)i) {
            status = 1;
        }
        if (i + 1 < 397 && h->bin[i + 1] != (double)(i + 1)) {
            status = 1;
        }
    }
}
