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
    if (n4 <= 0) return;
    for (k = 0; k < n4; k++) {
        if (k % 2 == 0) {
            output[k] = -output[n2 - k - 1];
        } else {
            output[n - k - 1] = output[n2 + k];
        }
    }
}
