#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *light;
extern double abs_val;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (plane = 0; plane < 1; ++plane) {
    for (int inner = 0; inner < 3; ++inner) {
        light[inner] = (light[inner] / abs_val);
        if (!light[inner]) {
            light[inner] = 1.;
        }
    }
}
}
