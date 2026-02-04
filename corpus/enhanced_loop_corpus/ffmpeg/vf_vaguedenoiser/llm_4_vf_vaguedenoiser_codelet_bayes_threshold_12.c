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
    float local_mean = 0.0f;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            local_mean += block[x] * block[x];
        }
        block += stride;
    }
    mean = local_mean;
}
