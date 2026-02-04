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
        if (k % 8 == 0) {
            output[k] = -output[n2 - k - 1];
            output[k + 1] = -output[n2 - k - 2];
            output[k + 2] = -output[n2 - k - 3];
            output[k + 3] = -output[n2 - k - 4];
        } else {
            output[k] = output[n2 - k - 1];
            output[k + 1] = output[n2 - k - 2];
            output[k + 2] = output[n2 - k - 3];
            output[k + 3] = output[n2 - k - 4];
        }
        output[n - k - 1] = output[n2 + k];
        output[n - k - 2] = output[n2 + k + 1];
        output[n - k - 3] = output[n2 + k + 2];
        output[n - k - 4] = output[n2 + k + 3];
    }
}
