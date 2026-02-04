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
        double val = light[plane] / abs_val;
        if (val != 0.0) {
            light[plane] = val;
        } else {
            light[plane] = 1.0;
        }
    }
}
