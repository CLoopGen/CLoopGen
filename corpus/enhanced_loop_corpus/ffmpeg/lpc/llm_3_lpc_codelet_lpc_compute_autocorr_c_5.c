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
    double *dptr = data + j;
    for (i = j; i < len; i++) {
        sum0 += dptr[i - j] * dptr[i - j - j];
        sum1 += dptr[i - j] * dptr[i - j - j - 1];
    }
    autoc[j] = sum0;
    autoc[j + 1] = sum1;
}
}
