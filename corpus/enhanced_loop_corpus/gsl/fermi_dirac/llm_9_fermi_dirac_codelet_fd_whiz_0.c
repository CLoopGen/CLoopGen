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
for (j = iterm - 1; j >= 0; j--) {
    double c = factor * (j + 1.) / (iterm + 1.);
    factor *= ratio;
    qden[j] = qden[j + 1] - c * qden[j] + c * c * qden[j];
    qnum[j] = qnum[j + 1] - c * qnum[j] + c * c * qnum[j];
    qden[j] *= (1.0 + 0.1 * c);
    qnum[j] *= (1.0 + 0.1 * c);
}
}
