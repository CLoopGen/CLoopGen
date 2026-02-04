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
int *indices = (int*)alloca(iterm * sizeof(int));
for (int i = 0; i < iterm; i++) {
    indices[i] = i;
}
for (j = iterm - 1; j >= 0; j--) {
    int idx = indices[j]; // Indirect access via index array
    double c = factor * (idx + 1.) / (iterm + 1.);
    factor *= ratio;
    qden[idx] = qden[idx + 1] - c * qden[idx];
    qnum[idx] = qnum[idx + 1] - c * qnum[idx];
}
}
