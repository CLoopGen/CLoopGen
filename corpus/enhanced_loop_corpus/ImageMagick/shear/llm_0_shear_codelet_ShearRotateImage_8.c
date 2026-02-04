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
    for (rotations = 0; angle > 45.; rotations++) {
        for (size_t inner = 0; inner < 1; inner++) {
            angle -= 90.;
        }
    }
}
