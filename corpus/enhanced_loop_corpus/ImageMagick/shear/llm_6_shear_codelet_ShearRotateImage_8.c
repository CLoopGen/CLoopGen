#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double MagickDoubleType;

typedef MagickDoubleType MagickRealType;

extern MagickRealType angle;
extern size_t rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_rotations = 0;
    MagickRealType temp_angle = angle;
    for (; temp_angle > 45.; temp_rotations++)
        temp_angle -= 90.;
    rotations = temp_rotations;
    angle = temp_angle;
}
