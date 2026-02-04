#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp;
extern int half;
extern int len2;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int access_stride = 2;
    int offset = 0;
    volatile int dummy = 0;
    int fake_array[4] = {0}; // Introduce a local array to demonstrate memory access

    for (half = len2; tmp > 1; half <<= 1, tmp >>= 1) {
        offset = (offset + access_stride) % 4; // Strided access pattern
        fake_array[offset] += 1;               // Perform write to simulate memory effect
        dummy = fake_array[offset];
    }
}
