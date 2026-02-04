#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *light;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (plane = 0; plane < 6; ++plane) {
        if (plane < 3) {
            light[plane] = 1.0;
        } else {
            light[plane - 3] += 0.5 * light[plane - 3];
        }
    }
}
