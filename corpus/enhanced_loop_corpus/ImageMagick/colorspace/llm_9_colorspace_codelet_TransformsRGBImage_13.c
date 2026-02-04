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
for (i = 0; i <= (ssize_t)65535UL; i += 2) {
    MagickRealType val1 = (MagickRealType)(1. * (double)i);
    MagickRealType val2 = (MagickRealType)(1. * (double)(i + 1));
    x_map[i].x = val1;
    y_map[i].x = (MagickRealType)0.;
    z_map[i].x = (MagickRealType)0.;
    x_map[i].y = (MagickRealType)0.;
    y_map[i].y = val1;
    z_map[i].y = (MagickRealType)0.;
    x_map[i].z = (MagickRealType)0.;
    y_map[i].z = (MagickRealType)0.;
    z_map[i].z = val1;

    if (i + 1 <= (ssize_t)65535UL) {
        x_map[i+1].x = val2;
        y_map[i+1].x = (MagickRealType)0.;
        z_map[i+1].x = (MagickRealType)0.;
        x_map[i+1].y = (MagickRealType)0.;
        y_map[i+1].y = val2;
        z_map[i+1].y = (MagickRealType)0.;
        x_map[i+1].z = (MagickRealType)0.;
        y_map[i+1].z = (MagickRealType)0.;
        z_map[i+1].z = val2;
    }
}
}
