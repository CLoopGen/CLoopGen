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
        float temp = histogram[0];
        for (x = 0; x < hsize - 1; x++) {
            float next_val = histogram[x + 1];
            histogram[x] /= hsize;
            temp = next_val + temp;
            if (x + 1 < hsize - 1) {
                histogram[x + 1] = temp;
            }
        }
        if (hsize > 1) {
            histogram[hsize - 1] += temp;
        }
    }
}
