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
    float *row = &block[y * stride];
    for (int x = 0; x < width; x += 2) {
        mean += row[x] * row[x];
        if (x + 1 < width) {
            mean += row[x + 1] * row[x + 1];
        }
    }
}
}
