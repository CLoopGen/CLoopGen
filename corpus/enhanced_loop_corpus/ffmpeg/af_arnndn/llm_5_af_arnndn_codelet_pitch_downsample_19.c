#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float tmp;
extern float lpc[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float factor = 0.899999976F;
    for (int i = 0; i < 4; i++) {
        tmp = factor * tmp;
        if (tmp > 1e-5F) {
            lpc[i] = lpc[i] * tmp;
        } else {
            lpc[i] = 0.0F;
        }
    }
}
