#include <stdio.h>

#include <inttypes.h>

extern float delta_territory_cache[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2)
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    int stride = 2;
    for (ii = start; ii < end; ii += stride) {
        delta_territory_cache[ii] = (-2. * 19 * 19);
    }
}
