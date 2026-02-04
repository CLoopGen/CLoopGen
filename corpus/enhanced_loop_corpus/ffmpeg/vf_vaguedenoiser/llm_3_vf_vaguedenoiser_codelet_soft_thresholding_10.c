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
extern  float shift;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using index scaling (access every 2nd element, then handle remainder)
    for (y = 0; y < height; y++) {
        // First pass: process even indices with strided access pattern
        for (x = 0; x < width; x += 2) {
            float *elem = &block[x];
            const float temp = (*elem >= 0 ? *elem : -*elem);
            if (temp <= threshold)
                *elem *= frac;
            else
                *elem = (*elem < 0.F ? -1.F : (*elem > 0.F ? 1.F : 0.F)) * (temp - shift);
        }
        // Second pass: process odd indices to maintain full coverage
        for (x = 1; x < width; x += 2) {
            float *elem = &block[x];
            const float temp = (*elem >= 0 ? *elem : -*elem);
            if (temp <= threshold)
                *elem *= frac;
            else
                *elem = (*elem < 0.F ? -1.F : (*elem > 0.F ? 1.F : 0.F)) * (temp - shift);
        }
        block += stride;
    }
}
