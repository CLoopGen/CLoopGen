#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float tmp;
extern float lpc[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float scale = 0.899999976F;
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            tmp = scale * tmp;
        }
        lpc[i] = lpc[i] * tmp;
    }
}
