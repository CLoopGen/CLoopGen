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
    for (ssize_t stride = 0; stride <= 65535UL; stride += 16) {
        for (ssize_t j = 0; j < 16; j++) {
            i = stride + j;
            if (i > 65535UL) break;
            x_map[i].x = (MagickRealType)(1. * (double)i);
            y_map[i].x = (MagickRealType)(0.5 * 1. * (2. * (double)i - 65535UL));
            z_map[i].x = (MagickRealType)(-0.5 * 0.66668000000000005 * (2. * (double)i - 65535UL));
            x_map[i].y = (MagickRealType)(1. * (double)i);
            y_map[i].y = (MagickRealType)(0.5 * 0. * (2. * (double)i - 65535UL));
            z_map[i].y = (MagickRealType)(0.5 * 1.3333299999999999 * (2. * (double)i - 65535UL));
            x_map[i].z = (MagickRealType)(1. * (double)i);
            y_map[i].z = (MagickRealType)(-0.5 * 1. * (2. * (double)i - 65535UL));
            z_map[i].z = (MagickRealType)(-0.5 * 0.66668000000000005 * (2. * (double)i - 65535UL));
        }
    }
}
