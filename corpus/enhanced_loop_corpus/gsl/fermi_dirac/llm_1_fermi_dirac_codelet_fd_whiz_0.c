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
if (iterm > 0) {
    for (j = iterm - 1; j >= 0; j--) {
        double c = factor * (j + 1.) / (iterm + 1.);
        factor *= ratio;
        for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
            qden[j] = qden[j + 1] - c * qden[j];
            qnum[j] = qnum[j + 1] - c * qnum[j];
        }
    }
}
}
