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
        float prod0_0 = x[i + 0][0] * x[i + 0][0];
        float prod1_0 = x[i + 1][0] * x[i + 1][0];
        sum0 = sum0 + prod0_0 + prod1_0;

        float old_sum1 = sum1;
        float prod0_1 = x[i + 0][1] * x[i + 0][1];
        float prod1_1 = x[i + 1][1] * x[i + 1][1];
        sum1 = old_sum1 + prod0_1;
        sum1 = sum1 + prod1_1;
    }
}
