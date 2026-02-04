#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern float temp[54];
extern float gain;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    int stride = 2;
    for (i = 0; i < length; i += stride) {
        temp[i] *= gain;
    }
    for (i = 1; i < length; i += stride) {
        temp[i] *= gain;
    }
}
