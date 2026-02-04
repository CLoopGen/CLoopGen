#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *histogram;
extern size_t hsize;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < hsize - 2; x += 2) {
        histogram[x + 1] += histogram[x];
        histogram[x + 2] += histogram[x + 1];
        histogram[x] /= hsize;
        histogram[x + 1] /= hsize;
    }
    // Handle remaining elements if hsize is odd or leaves remainder
    if (x == hsize - 2) {
        histogram[x + 1] += histogram[x];
        histogram[x] /= hsize;
        histogram[x + 1] /= hsize;
    }
}
