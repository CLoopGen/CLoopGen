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
    size_t local_rotations = rotations;
    MagickRealType reduction = 0.0;
    for (size_t i = 0; angle - reduction > 45.; i++) {
        reduction += 90.0;
        local_rotations++;
    }
    rotations = local_rotations;
}
