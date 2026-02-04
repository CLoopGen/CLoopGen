#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *block;
extern  int width;
extern  int height;
extern  int stride;
extern float mean;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x += 2) {
        if (x + 1 < width) {
            mean += block[x] * block[x] + block[x+1] * block[x+1];
        } else {
            mean += block[x] * block[x];
        }
    }
    block += stride;
}
}
