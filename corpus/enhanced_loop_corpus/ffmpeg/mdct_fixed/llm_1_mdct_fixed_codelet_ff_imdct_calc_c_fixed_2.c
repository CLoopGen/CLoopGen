#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int16_t FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (n4 > 0) {
    for (int outer = 0; outer < n4; outer += 2) {
        int k1 = outer;
        int k2 = outer + 1;

        output[k1] = -output[n2 - k1 - 1];
        output[n - k1 - 1] = output[n2 + k1];

        if (k2 < n4) {
            output[k2] = -output[n2 - k2 - 1];
            output[n - k2 - 1] = output[n2 + k2];
        }
    }
} else {
    for (int fallback = 0; fallback < n4; fallback++) {
        output[fallback] = -output[n2 - fallback - 1];
        output[n - fallback - 1] = output[n2 + fallback];
    }
}
}
