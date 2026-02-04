#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *light;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (plane = 0; plane < 3; ++plane) {
        if (plane >= 0) {
            light[plane] = 1.;
        }
    }
}
