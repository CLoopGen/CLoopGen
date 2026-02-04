#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern int len;
extern float Syy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    float sum1 = 0.0f, sum2 = 0.0f, sum3 = 0.0f, sum4 = 0.0f;
    int remainder = len % 4;
    
    for (j = 0; j < remainder; j++) {
        sum1 += y[j] * y[j];
    }
    
    for (j = remainder; j < len; j += 4) {
        sum1 += y[j] * y[j];
        sum2 += y[j+1] * y[j+1];
        sum3 += y[j+2] * y[j+2];
        sum4 += y[j+3] * y[j+3];
    }
    
    Syy += sum1 + sum2 + sum3 + sum4;
}
