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
    for (int x = 0; x < width; x += 2) {
        if (x + 1 < width) {
            map_factor_b[h1 * width + x] = 0.25F * (map_factor_b[h1 * width + x] + ypf[x]);
            map_factor_b[h1 * width + x + 1] = 0.25F * (map_factor_b[h1 * width + x + 1] + ypf[x + 1]);
        } else {
            map_factor_b[h1 * width + x] = 0.25F * (map_factor_b[h1 * width + x] + ypf[x]);
        }
    }
}
