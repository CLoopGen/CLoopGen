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
for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
        float val = block[x];
        float abs_val = val;
        if (abs_val < 0) abs_val = -abs_val;

        // Introduce early skip condition based on magnitude
        if (abs_val <= threshold * 0.5f) {
            block[x] = 0.0f;  // Aggressive attenuation for very small values
            continue;
        }

        float tp2 = abs_val * abs_val;
        if (abs_val <= threshold) {
            block[x] *= frac;
        } else {
            block[x] *= (tp2 - tr2) / tp2;
        }
    }
    block += stride;
}
}
