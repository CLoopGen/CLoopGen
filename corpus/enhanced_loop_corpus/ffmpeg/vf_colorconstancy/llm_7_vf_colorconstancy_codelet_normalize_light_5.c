#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *light;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    light[0] = 1.;
    for (plane = 1; plane < 3; ++plane) {
        light[plane] = light[plane - 1]; // Introduce RAW and loop-carried dependence
    }
}
