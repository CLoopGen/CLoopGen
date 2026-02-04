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
for (i = 0; i <= (ssize_t)65535UL; i++) {
    MagickRealType temp_i = (MagickRealType)(double)i;
    MagickRealType temp_val = (MagickRealType)(2. * (double)i - 65535UL);

    x_map[i].x = (MagickRealType)(1. * temp_i);
    y_map[i].x = (MagickRealType)(0.5 * 1. * temp_val);
    z_map[i].x = (MagickRealType)(-0.5 * 0.66668000000000005 * temp_val);
    x_map[i].y = (MagickRealType)(1. * temp_i);
    y_map[i].y = (MagickRealType)(0.5 * 0. * temp_val);
    z_map[i].y = (MagickRealType)(0.5 * 1.3333299999999999 * temp_val);
    x_map[i].z = (MagickRealType)(1. * temp_i);
    y_map[i].z = (MagickRealType)(-0.5 * 1. * temp_val);
    z_map[i].z = (MagickRealType)(-0.5 * 0.66668000000000005 * temp_val);
}
}
