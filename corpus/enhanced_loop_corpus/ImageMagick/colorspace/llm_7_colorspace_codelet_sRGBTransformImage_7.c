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
    MagickRealType prev_x = 0., prev_y = 0., prev_z = 0.;
    for (i = 0; i <= (ssize_t)65535UL; i++) {
        MagickRealType curr_x = (MagickRealType)(1. * (double)i) + prev_x;
        MagickRealType curr_y = (MagickRealType)(1. * (double)i) + prev_y;
        MagickRealType curr_z = (MagickRealType)(1. * (double)i) + prev_z;
        x_map[i].x = curr_x;
        x_map[i].y = (MagickRealType)0.;
        x_map[i].z = (MagickRealType)0.;
        y_map[i].x = (MagickRealType)0.;
        y_map[i].y = curr_y;
        y_map[i].z = (MagickRealType)0.;
        z_map[i].x = (MagickRealType)0.;
        z_map[i].y = (MagickRealType)0.;
        z_map[i].z = curr_z;
        prev_x = curr_x;
        prev_y = curr_y;
        prev_z = curr_z;
    }
}
