#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *light;
extern double abs_val;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal
    for (plane = 2; plane >= 0; plane -= 1) {
        int idx = plane;
        light[idx] = (light[idx] / abs_val);
        if (!light[idx]) {
            light[idx] = 1.;
        }
    }
}
