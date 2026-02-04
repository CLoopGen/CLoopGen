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
    if (length <= 1) return;
    for (i = 0; i < length - 1; i++) {
        float prod = in[i] * in[i + 1];
        if (prod > 0) {
            sum2 += prod;
        }
    }
}
