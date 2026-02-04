#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern  float b0;
extern  float b1;
extern  float q;
extern  float c;
extern float *dst;
extern float g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int y = 1; y < height - 1; y++) {
    g = q * dst[y * width + (width - 1)] + c * dst[(y - 1) * width + (width - 1)];
    if (y % 2 == 0) {
        for (int x = width - 1; x >= 0; x--) {
            dst[y * width + x] = b0 * dst[y * width + x] + b1 * dst[(y - 1) * width + x] + g;
            g = q * dst[y * width + x] + c * dst[(y - 1) * width + x];
        }
    } else {
        float acc = 0.0f;
        for (int x = width - 1; x >= 0; x--) {
            int curr = y * width + x;
            int prev = (y - 1) * width + x;
            float new_val = b0 * dst[curr] + b1 * dst[prev] + g;
            acc += new_val;
            dst[curr] = new_val;
            g = q * dst[curr] + c * dst[prev];
        }
        g += acc * 0.01f; // Slight state variation for odd rows
    }
}
}
