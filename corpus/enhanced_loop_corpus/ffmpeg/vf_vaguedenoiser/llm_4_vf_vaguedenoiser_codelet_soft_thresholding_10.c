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
for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
        const float val = block[x];
        const float temp = val >= 0 ? val : -val;
        const float sign = val < 0.F ? -1.F : (val > 0.F ? 1.F : 0.F);
        block[x] = (temp <= threshold) ? (val * frac) : (sign * (temp - shift));
    }
    block += stride;
}
}
