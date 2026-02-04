#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (k = 0; k < n4; k += step) {
        FFTSample temp1 = output[n2 + k];
        FFTSample temp2 = output[n2 - k - 1];
        output[k] = -temp2;
        output[n - k - 1] = temp1;

        // Introduce additional arithmetic to increase computational intensity
        output[k] += (FFTSample)(k * 0.5f);
        output[n - k - 1] *= (FFTSample)(1.0f + k * 0.1f);
    }
}
