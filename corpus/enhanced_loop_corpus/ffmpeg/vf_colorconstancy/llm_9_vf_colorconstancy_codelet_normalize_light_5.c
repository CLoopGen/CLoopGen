#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *light;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (plane = 0; plane < 3; ++plane) {
        light[plane] = 1.0;
        light[plane] = light[plane] * 2.0 - 0.5;
        light[plane] = light[plane] / 1.5;
    }
}
