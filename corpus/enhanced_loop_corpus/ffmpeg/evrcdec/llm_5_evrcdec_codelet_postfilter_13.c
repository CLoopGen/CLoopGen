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
    sum2 = 0;
    for (i = 0; i < length - 1; i += 2) {
        if (i + 1 < length - 1) {
            sum2 += in[i] * in[i + 1];
        }
    }
    if (length % 2 == 0 && length > 1) {
        sum2 += in[length - 2] * in[length - 1];
    }
}
