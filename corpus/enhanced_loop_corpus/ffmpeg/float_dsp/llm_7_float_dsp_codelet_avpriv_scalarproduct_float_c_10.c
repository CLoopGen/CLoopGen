#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *v1;
extern  float *v2;
extern int len;
extern float p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float sum1 = 0.0f, sum2 = 0.0f;
    int remainder = len % 2;
    int unroll_len = len - remainder;
    for (i = 0; i < unroll_len; i += 2) {
        sum1 += v1[i] * v2[i];
        sum2 += v1[i+1] * v2[i+1];
    }
    for (; i < len; i++)
        sum1 += v1[i] * v2[i];
    p += sum1 + sum2;
}
