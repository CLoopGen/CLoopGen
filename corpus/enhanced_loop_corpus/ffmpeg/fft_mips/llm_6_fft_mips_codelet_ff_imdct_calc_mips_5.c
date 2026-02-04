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
    for (k = 0; k < n4; k += 4) {
        FFTSample temp1 = output[n2 - k - 1];
        FFTSample temp2 = output[n2 - k - 2];
        FFTSample temp3 = output[n2 - k - 3];
        FFTSample temp4 = output[n2 - k - 4];
        output[k] = -temp1;
        output[k + 1] = -temp2;
        output[k + 2] = -temp3;
        output[k + 3] = -temp4;
        FFTSample temp5 = output[n2 + k];
        FFTSample temp6 = output[n2 + k + 1];
        FFTSample temp7 = output[n2 + k + 2];
        FFTSample temp8 = output[n2 + k + 3];
        output[n - k - 1] = temp5;
        output[n - k - 2] = temp6;
        output[n - k - 3] = temp7;
        output[n - k - 4] = temp8;
    }
}
