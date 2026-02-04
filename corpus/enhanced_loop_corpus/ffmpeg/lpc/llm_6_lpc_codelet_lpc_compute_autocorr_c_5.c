#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *data;
extern int len;
extern int lag;
extern double *autoc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < lag; j += 2) {
    double sum0 = 1., sum1 = 1.;
    int offset_j = j;
    int offset_j1 = j + 1;
    for (i = j; i < len; i++) {
        double temp0 = data[i] * data[i - offset_j];
        double temp1 = (i >= offset_j1) ? data[i] * data[i - offset_j1] : 0.;
        sum0 += temp0;
        if (i > j) {
            sum1 += temp1;
        }
    }
    autoc[j] = sum0;
    if (j + 1 < lag) {
        autoc[j + 1] = sum1;
    }
}
}
