#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *data;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n - 2; i += 2) {
        FFTSample temp1 = data[i - 1];
        FFTSample temp2 = data[i + 2];
        data[i + 1] += temp1;
        data[i] = -temp2;
    }
}
