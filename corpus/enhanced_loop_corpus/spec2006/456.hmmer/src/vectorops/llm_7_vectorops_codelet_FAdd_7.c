#include <stdio.h>

#include <inttypes.h>

extern float *vec1;
extern float *vec2;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    float temp = 0.0f;
    for (i = 0; i < n; i++) {
        temp += vec2[i];       // Eliminate loop-carried data dependency on output; accumulate locally
        vec1[i] = temp;        // Independent writes to vec1, no dependency chain across iterations
    }
}
