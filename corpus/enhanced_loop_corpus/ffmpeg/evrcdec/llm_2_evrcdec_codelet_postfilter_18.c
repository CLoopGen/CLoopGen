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
for (i = 0 , sum1 = 0 , sum2 = 0; i < length; i += 2) {
    sum1 += in[i] * in[i];
    if (i + 1 < length) {
        sum1 += in[i + 1] * in[i + 1];
    }
    sum2 += scratch[i] * scratch[i];
    if (i + 1 < length) {
        sum2 += scratch[i + 1] * scratch[i + 1];
    }
}
}
