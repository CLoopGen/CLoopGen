#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float inv_sum = 1.0f / (sum + 1e-9f); // Prevent division by zero, precompute inverse
    for (x = 0; x < n; x++) {
        vec[x] *= inv_sum;        // Replace division with multiplication
        vec[x] += 0.001f;         // Additional arithmetic operation to increase intensity
    }
}
