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
extern TransformPacket *x_map;
extern TransformPacket *y_map;
extern TransformPacket *z_map;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= (ssize_t)65535UL; i += 2) {
    MagickRealType idx = (MagickRealType)(1. * (double)i);
    MagickRealType idx_plus_one = (MagickRealType)(1. * (double)(i + 1));
    x_map[i].x = idx;
    x_map[i].y = (MagickRealType)0.;
    x_map[i].z = (MagickRealType)0.;
    y_map[i].x = (MagickRealType)0.;
    y_map[i].y = idx;
    y_map[i].z = (MagickRealType)0.;
    z_map[i].x = (MagickRealType)0.;
    z_map[i].y = (MagickRealType)0.;
    z_map[i].z = idx;

    if (i + 1 <= (ssize_t)65535UL) {
        x_map[i+1].x = idx_plus_one;
        x_map[i+1].y = (MagickRealType)0.;
        x_map[i+1].z = (MagickRealType)0.;
        y_map[i+1].x = (MagickRealType)0.;
        y_map[i+1].y = idx_plus_one;
        y_map[i+1].z = (MagickRealType)0.;
        z_map[i+1].x = (MagickRealType)0.;
        z_map[i+1].y = (MagickRealType)0.;
        z_map[i+1].z = idx_plus_one;
    }
}
}
