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
    for (x = 0; x < width; x += 2) {
        const float temp1 = ((block[x]) >= 0 ? (block[x]) : (-(block[x])));
        const float sign1 = (block[x] < 0.F ? -1.F : (block[x] > 0.F ? 1.F : 0.F));
        if (x + 1 < width) {
            const float temp2 = ((block[x+1]) >= 0 ? (block[x+1]) : (-(block[x+1])));
            const float sign2 = (block[x+1] < 0.F ? -1.F : (block[x+1] > 0.F ? 1.F : 0.F));
            block[x] = (temp1 <= threshold) ? (block[x] * frac) : (sign1 * (temp1 - shift));
            block[x+1] = (temp2 <= threshold) ? (block[x+1] * frac) : (sign2 * (temp2 - shift));
        } else {
            block[x] = (temp1 <= threshold) ? (block[x] * frac) : (sign1 * (temp1 - shift));
        }
    }
    block += stride;
}
}
