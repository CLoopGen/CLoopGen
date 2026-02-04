#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern float sum;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_sum1 = 0.0f, local_sum2 = 0.0f;
    int i;
    for (i = 0; i < n - 1; i += 2) {
        local_sum1 += vec[i];
        local_sum2 += vec[i + 1];
    }
    if (i == n - 1)
        local_sum1 += vec[i];
    sum = local_sum1 + local_sum2;
}
