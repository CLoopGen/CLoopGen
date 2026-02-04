#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *histogram;
extern size_t hsize;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access with consecutive backward traversal
    // Alters memory access direction to exploit different cache behavior
    for (x = hsize - 2; x >= 0; x--) {
        histogram[x + 1] += histogram[x];
        histogram[x] /= hsize;
    }
}
