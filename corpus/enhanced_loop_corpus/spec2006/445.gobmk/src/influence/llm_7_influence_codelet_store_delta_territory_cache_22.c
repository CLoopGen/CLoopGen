#include <stdio.h>

#include <inttypes.h>

extern float delta_territory_cache[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev = (19 + 2);
    for (ii = (19 + 2) + 1; ii < (19 + 1) * (19 + 1); ii++) {
        delta_territory_cache[ii] = delta_territory_cache[prev] + (-2. * 19 * 19);
        prev = ii;
    }
}
