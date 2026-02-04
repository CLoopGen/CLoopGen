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
    if (j >= len) continue;
    for (i = j; i < len; i++) {
        sum0 += data[i] * data[i - j];
        if (i - j - 1 >= 0) {
            sum1 += data[i] * data[i - j - 1];
        }
    }
    autoc[j] = sum0;
    if (j + 1 < lag) {
        autoc[j + 1] = sum1;
    }
}
}
