#include <stdio.h>

#include <inttypes.h>

extern float delta_territory_cache[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++)
    delta_territory_cache[ii] = (-2. * 19 * 19);

}
