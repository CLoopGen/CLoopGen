#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float tmp;
extern float lpc[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float acc = 1.0F;
    for (int i = 0; i < 4; i++) {
        acc *= 0.899999976F;
        lpc[i] = lpc[i] * (acc * tmp); // RAW dependency introduced: each lpc[i] depends on accumulated scaling
    }
    // Loop-carried dependency now in acc instead of directly in tmp; tmp is read-only
}
