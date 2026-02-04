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
    MagickRealType val = (MagickRealType)((double)i * 1.0);
    x_map[i].x = val;
    y_map[i].x = (MagickRealType)0.;
    z_map[i].x = (MagickRealType)0.;
    x_map[i].y = (MagickRealType)0.;
    y_map[i].y = val;
    z_map[i].y = (MagickRealType)0.;
    x_map[i].z = (MagickRealType)0.;
    y_map[i].z = (MagickRealType)0.;
    z_map[i].z = val;
}
}
