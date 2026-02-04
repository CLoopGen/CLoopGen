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
    for (int x = 0; x < width; x++) {
        float avg = 0.5F * (map_factor_b[h1 * width + x] + ypf[x]);
        float sq = avg * avg;
        float cube = sq * avg;
        map_factor_b[h1 * width + x] = cube;
    }
}
