#include <stdio.h>

#include <inttypes.h>

extern float delta_territory_cache[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float val = -2.0f * 19.0f * 19.0f;
    int start = 20;
    int end = 361;
    for (ii = start; ii < end; ii++) {
        delta_territory_cache[ii] = val;
        delta_territory_cache[ii + 1] *= val / (val - 1.0f); // Additional arithmetic to increase computational intensity
        ii++;
    }
}
