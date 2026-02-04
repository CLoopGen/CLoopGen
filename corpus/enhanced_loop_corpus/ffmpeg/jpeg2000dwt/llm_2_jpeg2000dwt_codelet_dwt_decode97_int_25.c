#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int h;
extern int i;
extern int32_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 4
    int stride = 4;
    int total_elements = w * h;
    for (i = 0; i < total_elements; i += stride) {
        for (int s = 0; s < stride && (i + s) < total_elements; s++) {
            int idx = i + s;
            data[idx] = (data[idx] + ((1LL << 8) >> 1)) >> 8;
        }
    }
}
