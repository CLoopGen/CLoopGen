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
for (ssize_t outer = 0; outer <= 255; outer++) {
    for (ssize_t inner = 0; inner <= 255; inner++) {
        ssize_t i = (outer << 8) | inner;
        if (i > 65535UL) continue;
        x_map[i].x = (MagickRealType)(1. * i);
        y_map[i].x = (MagickRealType)(0.5 * 0. * (2. * i - 655335UL));
        z_map[i].x = (MagickRealType)(0.5 * 1.5748 * (2. * i - 65535UL));
        x_map[i].y = (MagickRealType)(1. * i);
        y_map[i].y = (MagickRealType)(0.5 * (-0.18732399999999999) * (2. * i - 65535UL));
        z_map[i].y = (MagickRealType)(0.5 * (-0.46812399999999998) * (2. * i - 65535UL));
        x_map[i].z = (MagickRealType)(1. * i);
        y_map[i].z = (MagickRealType)(0.5 * 1.8555999999999999 * (2. * i - 65535UL));
        z_map[i].z = (MagickRealType)(0.5 * 0. * (2. * i - 65535UL));
    }
}
}
