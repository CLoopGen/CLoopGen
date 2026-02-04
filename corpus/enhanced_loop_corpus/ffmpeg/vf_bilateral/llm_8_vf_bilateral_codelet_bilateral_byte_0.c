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
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled loop by factor of 2
    for (int x = 0; x < width; x += 2) {
        int idx1 = h1 * width + x;
        int idx2 = (x + 1 < width) ? h1 * width + x + 1 : idx1;

        // First element update with extra computation (simulated higher complexity)
        float temp1 = map_factor_b[idx1] + ypf[x];
        map_factor_b[idx1] = 0.5F * temp1 + 0.1F * temp1 * temp1;

        // Second element (if valid) with similar enhancement
        if (x + 1 < width) {
            float temp2 = map_factor_b[idx2] + ypf[x + 1];
            map_factor_b[idx2] = 0.5F * temp2 + 0.1F * temp2 * temp2;
        }
    }
}
