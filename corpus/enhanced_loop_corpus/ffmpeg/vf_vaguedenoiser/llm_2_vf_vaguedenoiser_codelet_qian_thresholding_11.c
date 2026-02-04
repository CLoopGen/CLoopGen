#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *block;
extern  int width;
extern  int height;
extern  int stride;
extern  float threshold;
extern  float tr2;
extern  float frac;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    float *ptr = block;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            const float val = ptr[x];
            const float temp = val >= 0 ? val : -val;
            if (temp <= threshold) {
                ptr[x] *= frac;
            } else {
                const float tp2 = temp * temp;
                ptr[x] *= (tp2 - tr2) / tp2;
            }
        }
        ptr += stride;
    }
}
