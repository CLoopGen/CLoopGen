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
    for (y = 0; y < height; y += 2) {
        for (x = 0; x < width; x++) {
            float abs_val = block[x] >= 0 ? block[x] : -block[x];
            if (abs_val <= threshold) {
                block[x] *= frac;
                if (x + 1 < width) {
                    float abs_next = block[x + 1] >= 0 ? block[x + 1] : -block[x + 1];
                    if (abs_next <= threshold)
                        block[x + 1] *= frac;
                }
            }
        }
        block += stride;
        if (y + 1 < height) {
            block += stride;
        }
    }
}
