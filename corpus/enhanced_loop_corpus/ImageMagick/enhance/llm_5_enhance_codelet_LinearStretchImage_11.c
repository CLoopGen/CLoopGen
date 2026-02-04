#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double white_point;
extern double *histogram;
extern double intensity;
extern ssize_t white;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t temp_white = 65535UL;
    for (; temp_white > 0 && intensity < white_point; temp_white--) {
        intensity += histogram[temp_white];
    }
    white = temp_white;
}
