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
for (j = iterm - 1; j >= 0; j -= 2) {
    double c1 = factor * (j + 1.) / (iterm + 1.);
    double c2 = factor * (j + 0.) / (iterm + 1.);
    double temp_factor1 = factor;
    double temp_factor2 = factor * ratio;
    factor *= ratio * ratio;
    if (j >= 1) {
        qden[j] = qden[j + 1] - c1 * qden[j];
        qden[j-1] = qden[j] - c2 * qden[j-1];
        qnum[j] = qnum[j + 1] - c1 * qnum[j];
        qnum[j-1] = qnum[j] - c2 * qnum[j-1];
    } else {
        qden[j] = qden[j + 1] - c1 * qden[j];
        qnum[j] = qnum[j + 1] - c1 * qnum[j];
    }
}
}
