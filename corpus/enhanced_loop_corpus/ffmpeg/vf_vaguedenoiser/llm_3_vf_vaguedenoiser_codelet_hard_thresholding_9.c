#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *block;
extern  int width;
extern  int height;
extern  int stride;
extern  float threshold;
extern  float frac;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using index scaling (access every 2nd element, then handle remainder)
    for (y = 0; y < height; y++) {
        // First pass: process even indices with larger stride in data
        for (x = 0; x < width; x += 2) {
            float val = block[x];
            if ((val >= 0 ? val : -val) <= threshold)
                block[x] *= frac;
        }
        // Second pass: process odd indices (interleaved pattern)
        for (x = 1; x < width; x += 2) {
            float val = block[x];
            if ((val >= 0 ? val : -val) <= threshold)
                block[x] *= frac;
        }
        block += stride;
    }
}
