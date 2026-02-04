#include <stdio.h>

#include <inttypes.h>

extern float delta_territory_cache[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 20; ii < 400; ii += 2) {
        delta_territory_cache[ii] = (-2.0f * 19.0f * 19.0f);
        delta_territory_cache[ii + 1] = (-2.0f * 19.0f * 19.0f);
    }
}
