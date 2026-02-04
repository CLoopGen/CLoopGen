#include <stdio.h>

#include <inttypes.h>

extern float delta_territory_cache[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset base index
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    for (ii = start; ii < end; ii++) {
        delta_territory_cache[ii - start] = (-2. * 19 * 19);
    }
}
