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
        const float val = block[x];
        const float temp = val >= 0 ? val : -val;
        const float tp2 = temp * temp;
        const float adjusted = (tp2 - tr2) / tp2;
        // Eliminate conditional by using arithmetic masking
        const float mask = (temp > threshold);
        block[x] *= (1 - mask) * frac + mask * adjusted;
    }
    block += stride;
}
}
