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
for (i = 0; i <= 4; i++) {
    c[i] = 0.;
    for (j = 0; j <= 4; j += 2) {
        c[i] += V1inv[i * 5 + j] * fx[j * 8];
        if (j + 1 <= 4)
            c[i] += V1inv[i * 5 + (j + 1)] * fx[(j + 1) * 8];
    }
}
}
