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
    for (black = 0; black < (ssize_t)65535UL; black += 2) {
        intensity += histogram[black];
        if (black + 1 < (ssize_t)65535UL) {
            intensity += histogram[black + 1];
        }
        if (intensity >= black_point)
            break;
    }
}
