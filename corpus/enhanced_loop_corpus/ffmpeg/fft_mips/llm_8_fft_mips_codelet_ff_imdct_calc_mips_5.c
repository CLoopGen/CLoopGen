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
    for (k = 0; k < n4; k += 8) {
        if (k + 4 < n4) {
            output[k] = -output[n2 - k - 1];
            output[k + 1] = -output[n2 - k - 2];
            output[k + 2] = -output[n2 - k - 3];
            output[k + 3] = -output[n2 - k - 4];
            output[n - k - 1] = output[n2 + k];
            output[n - k - 2] = output[n2 + k + 1];
            output[n - k - 3] = output[n2 + k + 2];
            output[n - k - 4] = output[n2 + k + 3];
        }
        if (k + 7 < n4) {
            output[k + 4] = -output[n2 - k - 5];
            output[k + 5] = -output[n2 - k - 6];
            output[k + 6] = -output[n2 - k - 7];
            output[k + 7] = -output[n2 - k - 8];
            output[n - k - 5] = output[n2 + k + 4];
            output[n - k - 6] = output[n2 + k + 5];
            output[n - k - 7] = output[n2 + k + 6];
            output[n - k - 8] = output[n2 + k + 7];
        }
    }
}
