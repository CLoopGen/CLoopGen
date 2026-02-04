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
        float val = block[x];
        float abs_val = val;
        if (abs_val < 0) abs_val = -abs_val;

        float result;
        if (abs_val > threshold) {
            float sign = 0.F;
            if (val < 0.F) sign = -1.F;
            else if (val > 0.F) sign = 1.F;
            result = sign * (abs_val - shift);
        } else {
            result = val * frac;
        }
        block[x] = result;
    }
    block += stride;
}
}
