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
        for (k = 0; k < n4; k += 8) {
            int k1 = k;
            int k2 = k + 4;
            if (k1 < n4) {
                output[k1] = -output[n2 - k1 - 1];
                output[k1 + 1] = -output[n2 - k1 - 2];
                output[k1 + 2] = -output[n2 - k1 - 3];
                output[k1 + 3] = -output[n2 - k1 - 4];
                output[n - k1 - 1] = output[n2 + k1];
                output[n - k1 - 2] = output[n2 + k1 + 1];
                output[n - k1 - 3] = output[n2 + k1 + 2];
                output[n - k1 - 4] = output[n2 + k1 + 3];
            }
            if (k2 < n4) {
                output[k2] = -output[n2 - k2 - 1];
                output[k2 + 1] = -output[n2 - k2 - 2];
                output[k2 + 2] = -output[n2 - k2 - 3];
                output[k2 + 3] = -output[n2 - k2 - 4];
                output[n - k2 - 1] = output[n2 + k2];
                output[n - k2 - 2] = output[n2 + k2 + 1];
                output[n - k2 - 3] = output[n2 + k2 + 2];
                output[n - k2 - 4] = output[n2 + k2 + 3];
            }
        }
    }
}
