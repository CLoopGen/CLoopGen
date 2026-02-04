#include <stdio.h>

#include <inttypes.h>

extern float *vec1;
extern float *vec2;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a loop-carried WAW (Write-After-Write) dependency
    // and break the independence of iterations by making each write depend on the previous one.
    float temp = 0.0f;
    for (x = 0; x < n; x++) {
        temp = vec2[x] + temp;  // Accumulate with previous result
        vec1[x] = temp;         // Introduce WAW and loop-carried dependence
    }
}
