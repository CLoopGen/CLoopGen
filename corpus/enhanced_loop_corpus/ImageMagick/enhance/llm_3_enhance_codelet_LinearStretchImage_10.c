#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double black_point;
extern double *histogram;
extern double intensity;
extern ssize_t black;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse consecutive memory access (traverse from high to low index)
    intensity = 0.0;
    for (black = 65534; black >= 0; black--) {
        intensity += histogram[black];
        if (intensity >= black_point)
            break;
    }
}
