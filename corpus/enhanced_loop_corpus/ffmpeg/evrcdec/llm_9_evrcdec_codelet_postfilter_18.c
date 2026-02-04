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
    for (i = 0, sum1 = 0, sum2 = 0; i < length * 2; i++) {
        int idx = i / 2;
        if (i % 2 == 0) {
            sum1 += in[idx] * in[idx] + in[idx] * scratch[idx];
        } else {
            sum2 += scratch[idx] * scratch[idx] - in[idx] * scratch[idx];
        }
    }
}
