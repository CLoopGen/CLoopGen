#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h1;
extern gsl_histogram *g;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 397; i += 4) {
        if (h1->bin[i] != 0.25 + g->bin[i])
            status = 1;
        if (i + 1 < 397 && h1->bin[i + 1] != 0.25 + g->bin[i + 1])
            status = 1;
        if (i + 2 < 397 && h1->bin[i + 2] != 0.25 + g->bin[i + 2])
            status = 1;
        if (i + 3 < 397 && h1->bin[i + 3] != 0.25 + g->bin[i + 3])
            status = 1;
    }
}
