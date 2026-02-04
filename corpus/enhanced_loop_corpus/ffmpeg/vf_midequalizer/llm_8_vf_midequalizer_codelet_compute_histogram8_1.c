#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *histogram;
extern size_t hsize;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < hsize; x++) {
        if (x + 1 < hsize) {
            histogram[x + 1] += histogram[x] * 0.5f;
        }
        histogram[x] /= hsize;
        histogram[x] *= 2.0f;
    }
}
