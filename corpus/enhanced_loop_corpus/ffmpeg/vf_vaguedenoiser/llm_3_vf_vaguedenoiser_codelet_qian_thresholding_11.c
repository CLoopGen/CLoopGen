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
    // Variant 2: Strided memory access using index scaling (access every 2nd element in x, then handle remainder)
    for (int y = 0; y < height; y++) {
        // First pass: process even indices with stride of 2
        for (int x = 0; x < width; x += 2) {
            const float val = block[x];
            const float temp = val >= 0 ? val : -val;
            if (temp <= threshold) {
                block[x] *= frac;
            } else {
                const float tp2 = temp * temp;
                block[x] *= (tp2 - tr2) / tp2;
            }
        }
        // Second pass: process odd indices
        for (int x = 1; x < width; x += 2) {
            const float val = block[x];
            const float temp = val >= 0 ? val : -val;
            if (temp <= threshold) {
                block[x] *= frac;
            } else {
                const float tp2 = temp * temp;
                block[x] *= (tp2 - tr2) / tp2;
            }
        }
        block += stride;
    }
}
