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
for (i = 0; i <= (ssize_t)255UL; i++) {
    for (ssize_t j = 0; j <= (ssize_t)255UL; j++) {
        ssize_t index = i * 256 + j;
        if (index > (ssize_t)65535UL) break;
        x_map[index].x = (MagickRealType)(1. * (double)index);
        x_map[index].y = (MagickRealType)0.;
        x_map[index].z = (MagickRealType)0.;
        y_map[index].x = (MagickRealType)0.;
        y_map[index].y = (MagickRealType)(1. * (double)index);
        y_map[index].z = (MagickRealType)0.;
        z_map[index].x = (MagickRealType)0.;
        z_map[index].y = (MagickRealType)0.;
        z_map[index].z = (MagickRealType)(1. * (double)index);
    }
}
}
