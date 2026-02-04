#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double V1inv[25];
extern  double *fx;
extern double *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= 9; i++) {
    double sum1 = 0., sum2 = 0.;
    int idx1 = i / 2, idx2 = (i / 2) * 5;
    for (j = 0; j <= 4; j++) {
        int vidx = idx2 + j;
        int fidx = j * 8;
        sum1 += V1inv[vidx] * fx[fidx];
        if (i % 2 == 0 && i > 0)
            sum2 += V1inv[vidx - 5] * fx[fidx];
    }
    if (i < 5)
        c[i] = sum1;
    else if (i >= 5 && i < 10)
        c[i-5] += sum2;
}
}
