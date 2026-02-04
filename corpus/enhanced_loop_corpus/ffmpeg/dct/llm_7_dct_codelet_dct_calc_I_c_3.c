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
    FFTSample prev_val = data[1]; // Break loop-carried dependency by caching a value outside the loop
    for (i = 3; i <= n; i += 2) {
        FFTSample current = data[i];
        data[i] = prev_val - current; // Replaces data[i-2] with delayed use of older value (reduces RAW chain)
        prev_val = data[i - 2];      // Update prev_val from two steps back, weakening sequential dependence
    }
}
