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
    for (x = 0; x < width; x += 2) {
        const float temp1 = (block[x] >= 0 ? block[x] : -block[x]);
        if (temp1 <= threshold) {
            block[x] *= frac;
        } else {
            const float tp2_1 = temp1 * temp1;
            block[x] *= (tp2_1 - tr2) / tp2_1;
        }

        if (x + 1 < width) {
            const float temp2 = (block[x+1] >= 0 ? block[x+1] : -block[x+1]);
            if (temp2 <= threshold) {
                block[x+1] *= frac;
            } else {
                const float tp2_2 = temp2 * temp2;
                block[x+1] *= (tp2_2 - tr2) / tp2_2;
            }
        }
    }
    block += stride;
}
}
