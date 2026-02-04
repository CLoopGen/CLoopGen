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
    ssize_t stride = 16;
    for (i = 0; i <= (ssize_t)65535UL; i += stride) {
        for (ssize_t j = 0; j < stride && (i + j) <= 65535UL; j++) {
            ssize_t idx = i + j;
            x_map[idx].x = (MagickRealType)(1. * (double)idx);
            x_map[idx].y = (MagickRealType)0.;
            x_map[idx].z = (MagickRealType)0.;
            y_map[idx].x = (MagickRealType)0.;
            y_map[idx].y = (MagickRealType)(1. * (double)idx);
            y_map[idx].z = (MagickRealType)0.;
            z_map[idx].x = (MagickRealType)0.;
            z_map[idx].y = (MagickRealType)0.;
            z_map[idx].z = (MagickRealType)(1. * (double)idx);
        }
    }
}
