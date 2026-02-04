#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *histogram;
extern size_t hsize;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < hsize - 1; x++) {
    float temp = histogram[x];
    if (x % 2 == 0) {
        histogram[x + 1] += temp * 2.0f;
    } else {
        histogram[x + 1] += temp / 2.0f;
    }
    histogram[x] = temp / hsize;
}
}
