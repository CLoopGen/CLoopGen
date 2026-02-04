#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double V2inv[81];
extern  double *fx;
extern double *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= 8; i++) {
    c[i] = 0.;
    j = 0;
    for (; j <= 8; j++)
        c[i] += V2inv[i * 9 + j] * fx[j * 4];
}
}
