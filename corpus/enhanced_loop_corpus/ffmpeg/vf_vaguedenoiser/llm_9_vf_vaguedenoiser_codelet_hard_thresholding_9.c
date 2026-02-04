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
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x += 4) {
            for (int k = 0; k < 4 && (x + k) < width; k++) {
                float val = block[x + k];
                float abs_val = val < 0.0f ? -val : val;
                if (abs_val <= threshold) {
                    block[x + k] *= frac;
                }
            }
        }
        block += stride;
    }
}
