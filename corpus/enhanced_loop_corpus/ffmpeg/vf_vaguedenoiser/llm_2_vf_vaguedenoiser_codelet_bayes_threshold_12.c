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
for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
        float val = block[x];
        if (val != 0.0f) {
            mean += val * val;
        }
    }
    block += stride;
}
}
