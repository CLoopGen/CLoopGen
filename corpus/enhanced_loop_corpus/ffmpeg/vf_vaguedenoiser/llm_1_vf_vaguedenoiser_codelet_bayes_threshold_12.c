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
for (int idx = 0; idx < height * width; idx++) {
    int y = idx / width;
    int x = idx % width;
    float val = block[y * stride + x];
    mean += val * val;
}
}
