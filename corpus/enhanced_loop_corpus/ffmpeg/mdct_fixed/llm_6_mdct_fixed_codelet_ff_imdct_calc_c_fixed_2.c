#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int16_t FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < n4; i++) {
        FFTSample temp = output[n2 + i];
        output[i] = -output[n2 - i - 1];
        output[n - i - 1] = temp;
    }
}
