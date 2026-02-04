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
const ssize_t stride = 256;
for (i = 0; i < stride; i++) {
    for (ssize_t j = i; j <= 65535UL; j += stride) {
        x_map[j].x = (MagickRealType)(1. * (double)j);
        y_map[j].x = (MagickRealType)(0.5 * 1. * (2. * (double)j - 65535UL));
        z_map[j].x = (MagickRealType)(-0.5 * 0.66668000000000005 * (2. * (double)j - 65535UL));
        x_map[j].y = (MagickRealType)(1. * (double)j);
        y_map[j].y = (MagickRealType)(0.5 * 0. * (2. * (double)j - 65535UL));
        z_map[j].y = (MagickRealType)(0.5 * 1.3333299999999999 * (2. * (double)j - 65535UL));
        x_map[j].z = (MagickRealType)(1. * (double)j);
        y_map[j].z = (MagickRealType)(-0.5 * 1. * (2. * (double)j - 65535UL));
        z_map[j].z = (MagickRealType)(-0.5 * 0.66668000000000005 * (2. * (double)j - 65535UL));
    }
}
}
