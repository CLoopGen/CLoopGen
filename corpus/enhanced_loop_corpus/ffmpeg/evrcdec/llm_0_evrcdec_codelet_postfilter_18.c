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
    for (i = 0; i < length; i++) {
        sum1 += in[i] * in[i];
    }
    for (i = 0; i < length; i++) {
        sum2 += scratch[i] * scratch[i];
    }
}
