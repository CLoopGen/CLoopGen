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
for (i = 0; i <= (ssize_t)32767UL; i++) {
    MagickRealType base_val = (MagickRealType)(2. * i - 32767UL);
    x_map[i].x = (MagickRealType)(1. * i);
    y_map[i].x = (MagickRealType)(0.5 * 0. * base_val);
    z_map[i].x = (MagickRealType)(0.5 * 1.5748 * base_val);
    x_map[i].y = (MagickRealType)(1. * i);
    y_map[i].y = (MagickRealType)(0.5 * (-0.18732399999999999) * base_val);
    z_map[i].y = (MagickRealType)(0.5 * (-0.46812399999999998) * base_val);
    x_map[i].z = (MagickRealType)(1. * i);
    y_map[i].z = (MagickRealType)(0.5 * 1.8555999999999999 * base_val);
    z_map[i].z = (MagickRealType)(0.5 * 0. * base_val);
}
}
