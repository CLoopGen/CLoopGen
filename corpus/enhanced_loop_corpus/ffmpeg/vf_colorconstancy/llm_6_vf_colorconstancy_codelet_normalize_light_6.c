#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *light;
extern double abs_val;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[3];
    for (plane = 0; plane < 3; ++plane) {
        temp[plane] = light[plane] / abs_val;
    }
    for (plane = 0; plane < 3; ++plane) {
        light[plane] = temp[plane];
        if (!light[plane]) {
            light[plane] = 1.;
        }
    }
}
