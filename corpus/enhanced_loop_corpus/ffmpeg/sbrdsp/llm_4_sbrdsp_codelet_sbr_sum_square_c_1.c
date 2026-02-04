#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float (*x)[2];
extern int n;
extern float sum0;
extern float sum1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    if (i + 0 < n) {
        sum0 += x[i + 0][0] * x[i + 0][0];
        sum1 += x[i + 0][1] * x[i + 0][1];
    }
    if (i + 1 < n) {
        sum0 += x[i + 1][0] * x[i + 1][0];
        sum1 += x[i + 1][1] * x[i + 1][1];
    }
}
}
