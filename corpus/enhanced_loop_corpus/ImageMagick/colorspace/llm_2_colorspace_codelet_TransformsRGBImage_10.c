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
for (i = 0; i <= (ssize_t)65535UL; i += 4) {
    ssize_t j1 = i;
    ssize_t j2 = i + 1;
    ssize_t j3 = i + 2;
    ssize_t j4 = i + 3;

    if (j1 <= 65535UL) {
        x_map[j1].x = (MagickRealType)(1. * (double)j1);
        y_map[j1].x = (MagickRealType)(0.5 * 1. * (2. * (double)j1 - 65535UL));
        z_map[j1].x = (MagickRealType)(-0.5 * 0.66668000000000005 * (2. * (double)j1 - 65535UL));
        x_map[j1].y = (MagickRealType)(1. * (double)j1);
        y_map[j1].y = (MagickRealType)(0.5 * 0. * (2. * (double)j1 - 65535UL));
        z_map[j1].y = (MagickRealType)(0.5 * 1.3333299999999999 * (2. * (double)j1 - 65535UL));
        x_map[j1].z = (MagickRealType)(1. * (double)j1);
        y_map[j1].z = (MagickRealType)(-0.5 * 1. * (2. * (double)j1 - 65535UL));
        z_map[j1].z = (MagickRealType)(-0.5 * 0.66668000000000005 * (2. * (double)j1 - 65535UL));
    }

    if (j2 <= 65535UL) {
        x_map[j2].x = (MagickRealType)(1. * (double)j2);
        y_map[j2].x = (MagickRealType)(0.5 * 1. * (2. * (double)j2 - 65535UL));
        z_map[j2].x = (MagickRealType)(-0.5 * 0.66668000000000005 * (2. * (double)j2 - 65535UL));
        x_map[j2].y = (MagickRealType)(1. * (double)j2);
        y_map[j2].y = (MagickRealType)(0.5 * 0. * (2. * (double)j2 - 65535UL));
        z_map[j2].y = (MagickRealType)(0.5 * 1.3333299999999999 * (2. * (double)j2 - 65535UL));
        x_map[j2].z = (MagickRealType)(1. * (double)j2);
        y_map[j2].z = (MagickRealType)(-0.5 * 1. * (2. * (double)j2 - 65535UL));
        z_map[j2].z = (MagickRealType)(-0.5 * 0.66668000000000005 * (2. * (double)j2 - 65535UL));
    }

    if (j3 <= 65535UL) {
        x_map[j3].x = (MagickRealType)(1. * (double)j3);
        y_map[j3].x = (MagickRealType)(0.5 * 1. * (2. * (double)j3 - 65535UL));
        z_map[j3].x = (MagickRealType)(-0.5 * 0.66668000000000005 * (2. * (double)j3 - 65535UL));
        x_map[j3].y = (MagickRealType)(1. * (double)j3);
        y_map[j3].y = (MagickRealType)(0.5 * 0. * (2. * (double)j3 - 65535UL));
        z_map[j3].y = (MagickRealType)(0.5 * 1.3333299999999999 * (2. * (double)j3 - 65535UL));
        x_map[j3].z = (MagickRealType)(1. * (double)j3);
        y_map[j3].z = (MagickRealType)(-0.5 * 1. * (2. * (double)j3 - 65535UL));
        z_map[j3].z = (MagickRealType)(-0.5 * 0.66668000000000005 * (2. * (double)j3 - 65535UL));
    }

    if (j4 <= 65535UL) {
        x_map[j4].x = (MagickRealType)(1. * (double)j4);
        y_map[j4].x = (MagickRealType)(0.5 * 1. * (2. * (double)j4 - 65535UL));
        z_map[j4].x = (MagickRealType)(-0.5 * 0.66668000000000005 * (2. * (double)j4 - 65535UL));
        x_map[j4].y = (MagickRealType)(1. * (double)j4);
        y_map[j4].y = (MagickRealType)(0.5 * 0. * (2. * (double)j4 - 65535UL));
        z_map[j4].y = (MagickRealType)(0.5 * 1.3333299999999999 * (2. * (double)j4 - 65535UL));
        x_map[j4].z = (MagickRealType)(1. * (double)j4);
        y_map[j4].z = (MagickRealType)(-0.5 * 1. * (2. * (double)j4 - 65535UL));
        z_map[j4].z = (MagickRealType)(-0.5 * 0.66668000000000005 * (2. * (double)j4 - 65535UL));
    }
}
}
