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
    for (x = 0; x < width; x++) {
        float abs_val = block[x];
        if (abs_val < 0) abs_val = -abs_val;
        if (abs_val <= threshold) {
            block[x] *= frac;
        }
    }
    block += stride;
}
}
