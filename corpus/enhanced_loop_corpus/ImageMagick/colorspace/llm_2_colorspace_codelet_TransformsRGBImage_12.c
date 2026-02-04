#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double MagickDoubleType;

typedef MagickDoubleType MagickRealType;

typedef struct _TransformPacket {
    MagickRealType x;
    MagickRealType y;
    MagickRealType z;
} TransformPacket;

extern ssize_t i;
extern TransformPacket *y_map;
extern TransformPacket *x_map;
extern TransformPacket *z_map;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling by 2
    // Accesses are restructured to process two elements per iteration to improve spatial locality and enable better vectorization.
    ssize_t limit = (ssize_t)65535UL;
    for (i = 0; i <= limit; i += 2) {
        // Process i-th element
        x_map[i].x = (MagickRealType)(1. * i);
        y_map[i].x = (MagickRealType)(0.5 * 0. * (2. * i - 65535UL));
        z_map[i].x = (MagickRealType)(0.5 * 1.5748 * (2. * i - 65535UL));
        x_map[i].y = (MagickRealType)(1. * i);
        y_map[i].y = (MagickRealType)(0.5 * (-0.18732399999999999) * (2. * i - 65535UL));
        z_map[i].y = (MagickRealType)(0.5 * (-0.46812399999999998) * (2. * i - 65535UL));
        x_map[i].z = (MagickRealType)(1. * i);
        y_map[i].z = (MagickRealType)(0.5 * 1.8555999999999999 * (2. * i - 65535UL));
        z_map[i].z = (MagickRealType)(0.5 * 0. * (2. * i - 65535UL));

        // Process (i+1)-th element if within bounds
        if (i + 1 <= limit) {
            ssize_t j = i + 1;
            x_map[j].x = (MagickRealType)(1. * j);
            y_map[j].x = (MagickRealType)(0.5 * 0. * (2. * j - 65535UL));
            z_map[j].x = (MagickRealType)(0.5 * 1.5748 * (2. * j - 65535UL));
            x_map[j].y = (MagickRealType)(1. * j);
            y_map[j].y = (MagickRealType)(0.5 * (-0.18732399999999999) * (2. * j - 65535UL));
            z_map[j].y = (MagickRealType)(0.5 * (-0.46812399999999998) * (2. * j - 65535UL));
            x_map[j].z = (MagickRealType)(1. * j);
            y_map[j].z = (MagickRealType)(0.5 * 1.8555999999999999 * (2. * j - 65535UL));
            z_map[j].z = (MagickRealType)(0.5 * 0. * (2. * j - 65535UL));
        }
    }
}
