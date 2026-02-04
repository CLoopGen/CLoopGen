#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *a;
extern  float *b;
extern int length;
extern float sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_sum1 = 0.0f;
    float local_sum2 = 0.0f;
    float local_sum3 = 0.0f;
    float local_sum4 = 0.0f;
    int aligned_length = (length / 4) * 4;
    
    for (i = 0; i < aligned_length; i += 4) {
        local_sum1 += a[i] * b[i];
        local_sum2 += a[i+1] * b[i+1];
        local_sum3 += a[i+2] * b[i+2];
        local_sum4 += a[i+3] * b[i+3];
    }
    
    for (; i < length; i++) {
        sum += a[i] * b[i];
    }
    
    sum += local_sum1 + local_sum2 + local_sum3 + local_sum4;
}
