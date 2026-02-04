#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *histogram;
extern size_t hsize;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (hsize > 1) {
        for (x = 0; x < hsize - 1; x++) {
            for (int unroll = 0; unroll < 1; unroll++) {
                histogram[x + 1] += histogram[x];
                histogram[x] /= hsize;
            }
        }
    }
}
