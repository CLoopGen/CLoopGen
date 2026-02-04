#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *light;
extern int plane;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse iteration
    for (plane = 2; plane >= 0; --plane) {
        light[2 - plane] = 1.;
    }
}
