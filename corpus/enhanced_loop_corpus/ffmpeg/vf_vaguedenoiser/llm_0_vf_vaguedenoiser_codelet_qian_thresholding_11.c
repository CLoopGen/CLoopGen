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
    x = 0;
    if (x < width) {
        do {
            const float temp = ((block[x]) >= 0 ? (block[x]) : (-(block[x])));
            if (temp <= threshold) {
                block[x] *= frac;
            } else {
                const float tp2 = temp * temp;
                block[x] *= (tp2 - tr2) / tp2;
            }
            x++;
        } while (x < width);
    }
    block += stride;
}
}
