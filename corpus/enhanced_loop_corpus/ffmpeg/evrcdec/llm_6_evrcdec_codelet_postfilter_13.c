#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int length;
extern float sum2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_sum = 0.0f;
    for (i = 0; i < length - 1; i += 2) {
        if (i + 1 < length - 1) {
            temp_sum += in[i] * in[i + 1] + in[i + 1] * in[i + 2];
        } else {
            temp_sum += in[i] * in[i + 1];
        }
    }
    sum2 += temp_sum;
}
