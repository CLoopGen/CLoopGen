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
    float val0_0 = x[i + 0][0];
    float val0_1 = x[i + 0][1];
    sum0 += val0_0 * val0_0;
    sum1 += val0_1 * val0_1;

    if (i + 1 >= n) continue;

    float val1_0 = x[i + 1][0];
    float val1_1 = x[i + 1][1];
    sum0 += val1_0 * val1_0;
    sum1 += val1_1 * val1_1;
}
}
