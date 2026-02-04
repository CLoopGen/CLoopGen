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
    double local_intensity = 0.0;
    ssize_t step = 4;
    for (black = 0; black < (ssize_t)65535UL; black += step) {
        for (ssize_t inner = 0; inner < step; inner++) {
            ssize_t idx = black + inner;
            if (idx >= (ssize_t)65535UL) break;
            local_intensity += histogram[idx];
            if (local_intensity >= black_point) {
                intensity = local_intensity;
                return;
            }
        }
    }
    intensity = local_intensity;
}
