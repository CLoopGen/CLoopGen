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
    for (k = 0; k < n4; k++) {
        int valid_index1 = (n2 - k - 1) >= 0;
        int valid_index2 = (n2 + k) < n;
        
        if (valid_index1) {
            output[k] = -output[n2 - k - 1];
        } else {
            output[k] = 0.0f;
        }

        if (valid_index2) {
            output[n - k - 1] = output[n2 + k];
        } else {
            output[n - k - 1] = 0.0f;
        }
    }
}
