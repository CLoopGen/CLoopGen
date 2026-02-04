#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void **d;
extern void **p;
extern  void **s;
extern int nb_samples;
extern int channels;
extern int n;
extern int c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double **srcs = (double **)s;
double **dsts = (double **)d;
double **prvs = (double **)p;
for (n = 0; n < nb_samples; n++) {
    for (c = 0; c < channels; c++) {
        const double current = srcs[c][n];
        dsts[c][n] = current + prvs[c][0];
        prvs[c][0] = dsts[c][n];
    }
}
}
