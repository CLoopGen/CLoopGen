#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (iterate from end to start)
    for (x = n - 1; x >= 0; x--) {
        vec[x] = 1.0f / (float)n;
    }
}
