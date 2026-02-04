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
    int limit = n4 / 2;
    for (k = 0; k < limit; k++) {
        FFTSample temp1 = output[n2 + k];
        FFTSample temp2 = output[n2 - k - 1];
        output[k] = -temp2;
        output[n - k - 1] = temp1;
        output[limit + k] = -(output[n2 - (limit + k) - 1]);
        output[n - (limit + k) - 1] = output[n2 + limit + k];
    }
}
