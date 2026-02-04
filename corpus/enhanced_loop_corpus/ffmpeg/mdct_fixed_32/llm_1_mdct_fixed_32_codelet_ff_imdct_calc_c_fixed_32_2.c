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
    if (n4 > 0) {
        int k = 0;
        for (; k < n4; k += 2) { // Decreased effective loop depth by unrolling two iterations into one
            output[k] = -output[n2 - k - 1];
            output[n - k - 1] = output[n2 + k];
            if (k + 1 < n4) {
                output[k + 1] = -output[n2 - (k + 1) - 1];
                output[n - (k + 1) - 1] = output[n2 + (k + 1)];
            }
        }
    }
}
