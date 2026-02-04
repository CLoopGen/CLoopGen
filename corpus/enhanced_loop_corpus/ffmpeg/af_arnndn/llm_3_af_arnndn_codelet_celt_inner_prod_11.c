#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y;
extern int N;
extern float xy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access from end to beginning
    for (int i = N - 1; i >= 0; i--)
        xy += x[i] * y[i];
}
