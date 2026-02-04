#include <stdio.h>

#include <inttypes.h>

extern float delta_territory_cache[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = (19 + 2); i < (19 + 1) * (19 + 1); i += 2) {
        delta_territory_cache[i] = (-2. * 19 * 19);
        if (i + 1 < (19 + 1) * (19 + 1)) {
            delta_territory_cache[i + 1] = (-2. * 19 * 19);
        }
    }
}
