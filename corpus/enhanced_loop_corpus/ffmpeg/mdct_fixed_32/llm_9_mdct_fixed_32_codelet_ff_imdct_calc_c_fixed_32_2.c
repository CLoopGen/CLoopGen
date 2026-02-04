#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = n4 / 8;
    if (stride == 0) stride = 1;
    for (k = 0; k < n4; k += stride) {
        FFTSample temp1 = output[n2 + k];
        FFTSample temp2 = output[n2 - k - 1];
        output[k] = -temp2;
        output[n - k - 1] = temp1;
    }
}
