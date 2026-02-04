#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *histogram;
extern size_t hsize;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev = 0.0f;
    for (x = 0; x < hsize - 1; x++) {
        prev = histogram[x];
        histogram[x] /= hsize;
        histogram[x + 1] += prev;
    }
}
