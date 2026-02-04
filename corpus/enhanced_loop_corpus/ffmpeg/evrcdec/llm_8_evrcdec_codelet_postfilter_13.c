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
    for (i = 0; i < length - 2; i += 2) {
        sum2 += in[i] * in[i + 1] + in[i + 1] * in[i + 2];
    }
}
