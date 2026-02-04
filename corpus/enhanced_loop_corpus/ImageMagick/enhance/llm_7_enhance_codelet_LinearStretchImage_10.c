#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double black_point;
extern double *histogram;
extern double intensity;
extern ssize_t black;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_intensity = intensity;
    ssize_t local_black = black;
    for (; local_black < (ssize_t)65535UL; local_black++) {
        local_intensity += histogram[local_black];
        if (local_intensity >= black_point) {
            break;
        }
    }
    black = local_black;
    intensity = local_intensity;
}
