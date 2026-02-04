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
if (n4 > 0) {
    k = 0;
    for (; k < n4; k++) {
        output[k] = -output[n2 - k - 1];
        output[n - k - 1] = output[n2 + k];
        k++;
        if (k < n4) {
            output[k] = -output[n2 - k - 1];
            output[n - k - 1] = output[n2 + k];
        }
        k--;
    }
}
}
