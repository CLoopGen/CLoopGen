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
    double temp_qden, temp_qnum;
    for (j = iterm - 1; j >= 0; j--) {
        double c = factor * (j + 1.) / (iterm + 1.);
        factor *= ratio;
        temp_qden = qden[j + 1] - c * qden[j];
        temp_qnum = qnum[j + 1] - c * qnum[j];
        qden[j] = temp_qden;
        qnum[j] = temp_qnum;
    }
}
