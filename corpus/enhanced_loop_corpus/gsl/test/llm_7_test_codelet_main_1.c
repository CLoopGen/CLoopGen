#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern int i;
extern double f[100];
extern int status;
extern gsl_histogram *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_status = 0;
    for (i = 0; i < 99; i++) {  // Reduce loop iterations to create loop-carried dependency
        if (h->bin[i] != f[i]) {
            local_status += 1;  // Accumulate in local variable (WAW on local_status across iterations)
        }
        h->bin[i + 1] += h->bin[i] * 0.1;  // Introduce loop-carried RAW dependency: each iteration depends on previous bin value
    }
    if (local_status > 0) {
        status = 1;
    }
}
