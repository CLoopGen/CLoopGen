#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *light;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[3];
    for (plane = 0; plane < 3; ++plane) {
        temp[plane] = 1.;
    }
    for (plane = 0; plane < 3; ++plane) {
        light[plane] = temp[plane];
    }
}
