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
    if (angle <= 45.) {
        rotations = 0;
        return;
    }
    rotations = 0;
    for (; angle > 45.;) {
        angle -= 90.;
        rotations++;
    }
}
