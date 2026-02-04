#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *data;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 2; ++outer) {
    for (i = 1; i < n - 2; i += 2) {
        data[i + 1] += data[i - 1];
        data[i] = -data[i + 2];
    }
}
}
