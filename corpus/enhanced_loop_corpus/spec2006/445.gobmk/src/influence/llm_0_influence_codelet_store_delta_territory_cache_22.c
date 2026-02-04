#include <stdio.h>

#include <inttypes.h>

extern float delta_territory_cache[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer, inner;
    for (outer = 0; outer < (19 + 1); outer++) {
        for (inner = 0; inner < (19 + 1); inner++) {
            ii = outer * (19 + 1) + inner;
            if (ii > (19 + 2)) {
                delta_territory_cache[ii] = (-2. * 19 * 19);
            }
        }
    }
}
