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
extern gsl_histogram *g;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 397; i += 4) {
        for (size_t offset = 0; offset < 4 && (i + offset) < 397; offset++) {
            size_t idx = i + offset;
            if (h1->bin[idx] != g->bin[idx] * h->bin[idx])
                status = 1;
        }
    }
}
