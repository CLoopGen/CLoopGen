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
const ssize_t stride = 16;
for (i = 0; i < (ssize_t)65536UL; i++) {
    ssize_t j = (i % stride) * (65536UL / stride) + (i / stride);
    x_map[j].x = (MagickRealType)(1. * (double)j);
    y_map[j].x = (MagickRealType)0.;
    z_map[j].x = (MagickRealType)0.;
    x_map[j].y = (MagickRealType)0.;
    y_map[j].y = (MagickRealType)(1. * (double)j);
    z_map[j].y = (MagickRealType)0.;
    x_map[j].z = (MagickRealType)0.;
    y_map[j].z = (MagickRealType)0.;
    z_map[j].z = (MagickRealType)(1. * (double)j);
}
}
