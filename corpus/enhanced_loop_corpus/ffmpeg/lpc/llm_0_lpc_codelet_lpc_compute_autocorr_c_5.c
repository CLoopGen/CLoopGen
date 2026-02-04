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
    int i0 = j;
    int i1 = j + 1;
    for (i = j; i < len; i++) {
        sum0 += data[i] * data[i - j];
        if (i1 < len) {
            sum1 += data[i1] * data[i1 - j - 1];
            i1++;
        }
    }
    autoc[j] = sum0;
    autoc[j + 1] = sum1;
}
}
