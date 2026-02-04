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
    for (int nested = 0; nested < 1; ++nested) {
        light[plane] = (light[plane] / abs_val);
        if (!light[plane]) {
            light[plane] = 1.;
        }
    }
}
}
