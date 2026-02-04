#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *light;
extern double abs_val;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (plane = 0; plane < 6; ++plane) {
    int idx = plane % 3;
    light[idx] = (light[idx] * light[idx]) / (abs_val + 1.0);
    if (light[idx] < 1e-9 && light[idx] > -1e-9) {
        light[idx] = 2.0;
    }
}
}
