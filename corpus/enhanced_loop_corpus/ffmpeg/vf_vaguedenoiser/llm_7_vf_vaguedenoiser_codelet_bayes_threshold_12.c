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
for (int y = 0; y < height; y += 2) {
    for (int x = 0; x < width; x++) {
        float val = block[x];
        mean += val * val;
        if (y + 1 < height) {
            float val2 = ((float*)((char*)block + stride))[x];
            mean += val2 * val2;
        }
    }
    block += 2 * stride;
}
}
