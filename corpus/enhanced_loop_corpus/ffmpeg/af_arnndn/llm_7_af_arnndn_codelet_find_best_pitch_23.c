#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern int len;
extern float Syy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_sum1 = 0.0f;
    float local_sum2 = 0.0f;
    int j = 0;
    for (; j < len - 1; j += 2) {
        local_sum1 += y[j] * y[j];
        local_sum2 += y[j+1] * y[j+1];
    }
    if (j < len)
        local_sum1 += y[j] * y[j];
    Syy += local_sum1 + local_sum2;
}
