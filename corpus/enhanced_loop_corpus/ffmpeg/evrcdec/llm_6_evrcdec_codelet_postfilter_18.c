#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int length;
extern float scratch[54];
extern float sum1;
extern float sum2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_sum1 = 0, temp_sum2 = 0;
    for (i = 0; i < length; i++) {
        temp_sum1 += in[i] * in[i];
        temp_sum2 += scratch[i] * scratch[i];
    }
    sum1 = temp_sum1;
    sum2 = temp_sum2;
}
