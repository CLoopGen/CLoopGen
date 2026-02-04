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
    // Variant 2: Consecutive memory access with offset indexing
    // Instead of stepping by 2, we now process consecutive indices but adjust internal accesses
    // Here, we maintain similar data dependency but access elements in sequence
    for (i = 3; i <= n; i++)
        data[i] = data[i - 1] - data[i];
}
