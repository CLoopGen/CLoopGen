#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection shadow[400];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride 4, wrapping around using modulo to stay in bounds
    int start = 19 + 2;
    int size = (19 + 1) * (19 + 1);
    int stride = 4;
    int count = 0;
    int max_iterations = (size - start + stride - 1) / stride; // Ceiling division

    for (k = 0; k < max_iterations; k++) {
        int index = start + (k * stride);
        if (index < size) {
            active[index] = shadow[index];
        }
    }
}
