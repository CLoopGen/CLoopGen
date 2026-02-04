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
    MagickRealType delta = 90.0;
    MagickRealType threshold = 45.0;
    if (angle > threshold) {
        size_t steps = (size_t)((angle - threshold) / delta) + 1;
        rotations = steps;
        angle -= (MagickRealType)(steps * delta);
    }
}
