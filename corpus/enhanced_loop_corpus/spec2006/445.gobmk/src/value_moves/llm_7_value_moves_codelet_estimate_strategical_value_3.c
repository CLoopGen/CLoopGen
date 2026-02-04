#include <stdio.h>

#include <inttypes.h>

extern int aa;
extern float dragon_value[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = 19 + 2;
    int limit = (19 + 1) * (19 + 1);
    for (aa = start; aa < limit; aa++) {
        dragon_value[aa] = (float)((0.5 * aa - 3.2) * (0.1 + aa % 3));
    }
}
