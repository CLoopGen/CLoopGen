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
for (k = 0; k < n4; k++) {
    output[k] = -output[n2 - k - 1];
    output[n - k - 1] = output[n2 + k];
}

}
