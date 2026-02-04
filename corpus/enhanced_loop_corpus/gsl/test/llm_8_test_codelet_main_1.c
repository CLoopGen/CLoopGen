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
    for (i = 0; i < 50; i++) {
        if (h->bin[2*i] != f[2*i] || h->bin[2*i+1] != f[2*i+1]) {
            status = 1;
        }
    }
}
