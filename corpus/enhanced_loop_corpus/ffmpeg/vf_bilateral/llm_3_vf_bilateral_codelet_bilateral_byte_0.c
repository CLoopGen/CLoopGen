#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern float *map_factor_b;
extern float *ypf;
extern int h1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order traversal
    // Access array elements from the end to the beginning for improved cache behavior in some contexts
    int x;
    int base_index = h1 * width;
    for (x = width - 1; x >= 0; x--) {
        map_factor_b[base_index + x] = 0.5F * (map_factor_b[base_index + x] + ypf[x]);
    }
}
