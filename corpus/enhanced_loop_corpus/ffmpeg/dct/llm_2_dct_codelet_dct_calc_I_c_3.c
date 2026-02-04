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
    // Variant 1: Strided memory access with increased stride (access every 4th element starting from i=3)
    // This modifies the original step of +2 to effectively create a strided pattern over the original data
    for (i = 3; i <= n; i += 4)
        data[i] = data[i - 2] - data[i];
}
