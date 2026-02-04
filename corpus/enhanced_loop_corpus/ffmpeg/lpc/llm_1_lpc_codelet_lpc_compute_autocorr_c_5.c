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
double temp_sums[2];
for (j = 0; j < lag; j += 2) {
    temp_sums[0] = 1.;
    temp_sums[1] = 1.;
    for (i = j; i < len; i++) {
        temp_sums[0] += data[i] * data[i - j];
        if (i > j) {
            temp_sums[1] += data[i] * data[i - j - 1];
        }
    }
    autoc[j] = temp_sums[0];
    autoc[j + 1] = temp_sums[1];
}
}
