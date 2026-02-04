#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float tmp;
extern float lpc[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = tmp;
    for (int i = 0; i < 4; i++) {
        temp = 0.899999976F * temp;
        lpc[i] = lpc[i] * temp;
    }
    tmp = temp; // WAW dependency removed: final write to tmp is outside loop, no loop-carried dep on tmp
}
