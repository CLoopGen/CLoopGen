#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int iterm;
extern double *qnum;
extern double *qden;
extern double factor;
extern double ratio;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < iterm; j++) {
    int idx = iterm - 1 - j;
    double c = factor * (idx + 1.) / (iterm + 1.);
    factor *= ratio;
    qden[idx] = qden[idx + 1] - c * qden[idx];
    qnum[idx] = qnum[idx + 1] - c * qnum[idx];
}
}
