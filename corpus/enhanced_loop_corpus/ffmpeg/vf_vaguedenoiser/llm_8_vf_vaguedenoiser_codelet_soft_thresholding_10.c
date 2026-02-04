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
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x++) {
        const float temp1 = (block[x]) >= 0 ? (block[x]) : (-(block[x]));
        const float temp2 = (block[x + stride]) >= 0 ? (block[x + stride]) : (-(block[x + stride]));
        if (temp1 <= threshold)
            block[x] *= frac;
        else
            block[x] = (block[x] < 0.F ? -1.F : (block[x] > 0.F ? 1.F : 0.F)) * (temp1 - shift);
        if (temp2 <= threshold)
            block[x + stride] *= frac;
        else
            block[x + stride] = (block[x + stride] < 0.F ? -1.F : (block[x + stride] > 0.F ? 1.F : 0.F)) * (temp2 - shift);
    }
    block += 2 * stride;
}
}
