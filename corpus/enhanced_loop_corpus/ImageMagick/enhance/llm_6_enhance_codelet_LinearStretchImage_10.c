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
    double temp_intensity = 0.0;
    for (black = 0; black < (ssize_t)65535UL; black++) {
        temp_intensity += histogram[black];
        if (temp_intensity >= black_point) {
            intensity = temp_intensity;
            break;
        }
    }
    if (black == (ssize_t)65535UL) {
        intensity = temp_intensity;
    }
}
