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
    int valid0 = 1, valid1 = 1;
    if (j == 0) valid0 = 0;
    for (i = j; i < len && (valid0 || valid1); i++) {
        if (valid0) sum0 += data[i] * data[i - j];
        if (valid1 && (i - j - 1) >= 0) sum1 += data[i] * data[i - j - 1];
    }
    if (valid0) autoc[j] = sum0;
    if (valid1 && j + 1 < lag) autoc[j + 1] = sum1;
}
}
