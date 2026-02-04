#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float tmp;
extern float lpc[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 2; i++) {
    float t0 = lpc[0] * tmp;
    float t1 = lpc[1] * tmp;
    float t2 = lpc[2] * tmp;
    float t3 = lpc[3] * tmp;
    tmp = 0.899999976F * tmp;
    lpc[0] = t0;
    lpc[1] = t1;
    lpc[2] = t2;
    lpc[3] = t3;
}
}
