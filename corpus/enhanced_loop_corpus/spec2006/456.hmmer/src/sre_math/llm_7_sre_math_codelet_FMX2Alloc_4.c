#include <stdio.h>

#include <inttypes.h>

extern int rows;
extern int cols;
extern float **mx;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate loop-carried dependencies entirely by making each iteration independent
    // and using local indexing to remove address reuse patterns that imply dependency
    const float *base = mx[0];
    for (int r = 1; r < rows; r++) {
        float *computed_addr = (float*)((char*)base + r * cols * sizeof(float));
        mx[r] = computed_addr;  // No data dependency between iterations; all use invariant base
    }
}
