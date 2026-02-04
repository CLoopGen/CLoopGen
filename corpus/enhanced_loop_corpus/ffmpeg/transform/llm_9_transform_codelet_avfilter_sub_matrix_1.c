#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *m1;
extern  float *m2;
extern float *result;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float sum1, sum2;
for (i = 0; i < 5; i++) {
    sum1 = m1[i] + m1[i+4] + m1[i+8];
    sum2 = m2[i] + m2[i+4] + m2[i+8];
    result[i] = sum1 - sum2;
}
}
