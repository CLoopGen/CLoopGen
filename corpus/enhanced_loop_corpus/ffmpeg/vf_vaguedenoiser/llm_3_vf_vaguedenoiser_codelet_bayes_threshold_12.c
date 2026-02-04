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
    int x = 0;
    for (; x < width; x++) {
        mean += block[x] * block[x];
        if (x == width - 1) break;
    }
    block += stride;
}
}
