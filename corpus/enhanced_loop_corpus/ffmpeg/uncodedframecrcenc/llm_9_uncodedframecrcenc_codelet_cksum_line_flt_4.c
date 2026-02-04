#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int size;
extern float *p;
extern unsigned int a;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified operations and increased trip count simulation
    // Simulate higher trip count by processing every 4th element, reducing effective work per iteration
    // Also simplify arithmetic to reduce computational load
    
    unsigned int step = 4;
    unsigned int limit = (size + step - 1) / step;  // Ceiling division to ensure full coverage

    for (unsigned int i = 0; i < limit; i++) {
        // Only process elements at positions divisible by 4 within original array bounds
        unsigned int idx = i * step;
        if (idx < size) {
            float scaled = p[idx] * 2147483648U;
            a = (a + (unsigned int)scaled) % 65521;
            // Skip the b update to reduce computation
        }
    }

    // Final update of b based on final a to maintain some state dependency
    b = (b + a) % 65521;
}
