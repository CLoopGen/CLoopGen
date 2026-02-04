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
    rotations = 0;
    MagickRealType temp_angle = angle;
    while (temp_angle > 45.0) {
        temp_angle -= 45.0;
        rotations++;
    }
    angle = temp_angle;
}
