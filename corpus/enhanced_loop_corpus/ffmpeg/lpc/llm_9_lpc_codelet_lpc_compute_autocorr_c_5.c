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
    for (j = 0; j < lag; j += 4) {
        double sum0 = 1., sum1 = 1., sum2 = 1., sum3 = 1.;
        int bound = len - (len % 8); // Align to multiple of 8 for unrolling
        for (i = j; i < bound; i += 8) {
            sum0 += data[i] * data[i - j] + data[i+1] * data[i - j + 1];
            sum1 += data[i] * data[i - j - 1] + data[i+1] * data[i - j];
            sum2 += data[i+2] * data[i - j + 2] + data[i+3] * data[i - j + 3];
            sum3 += data[i+2] * data[i - j + 1] + data[i+3] * data[i - j + 2];
            sum0 += data[i+4] * data[i - j + 4] + data[i+5] * data[i - j + 5];
            sum1 += data[i+4] * data[i - j + 3] + data[i+5] * data[i - j + 4];
            sum2 += data[i+6] * data[i - j + 6] + data[i+7] * data[i - j + 7];
            sum3 += data[i+6] * data[i - j + 5] + data[i+7] * data[i - j + 6];
        }
        // Handle remaining elements
        for (; i < len; i++) {
            if (j < lag)           sum0 += data[i] * data[i - j];
            if (j + 1 < lag)       sum1 += data[i] * data[i - j - 1];
            if (j + 2 < lag)         sum2 += data[i] * data[i - j - 2];
            if (j + 3 < lag)         sum3 += data[i] * data[i - j - 3];
        }
        if (j < lag)           autoc[j]     = sum0;
        if (j + 1 < lag)       autoc[j+1]   = sum1;
        if (j + 2 < lag)       autoc[j+2]   = sum2;
        if (j + 3 < lag)       autoc[j+3]   = sum3;
    }
}
