#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *light;
extern double abs_val;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (plane = 0; plane < 3; ++plane) {
        double inv = abs_val ? 1.0 / abs_val : 1.0;
        double scaled = light[plane] * inv;
        light[plane] = scaled;
        if (scaled == 0.0) {
            light[plane] = 1.0;
        }
    }
}
