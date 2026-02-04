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
    float prev_val = 0.0f;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            float abs_val = (block[x] >= 0) ? block[x] : -block[x];
            if (abs_val <= threshold) {
                float new_val = block[x] * frac;
                // Introduce WAW and RAW dependency: current write affects next iteration's read
                if (x > 0) {
                    block[x] = new_val + prev_val * 0.1f; // artificial dependence on prior write
                } else {
                    block[x] = new_val;
                }
                prev_val = block[x];
            } else {
                prev_val = block[x]; // maintain continuity in data flow
            }
        }
        block += stride;
        prev_val = 0.0f; // reset at row boundary to limit loop-carried dependence
    }
}
