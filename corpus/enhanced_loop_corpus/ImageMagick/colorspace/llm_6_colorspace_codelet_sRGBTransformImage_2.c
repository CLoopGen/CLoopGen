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
for (i = 0; i <= (ssize_t)65535UL; i++) {
    MagickRealType val_i = (MagickRealType)(double)i;
    x_map[i].x = 0.33333000000000002 * val_i;
    y_map[i].x = 0.33334000000000003 * val_i;
    z_map[i].x = 0.33333000000000002 * val_i;
    x_map[i].y = 0.5 * val_i;
    z_map[i].y = -0.5 * val_i;
    y_map[i].y = 0.0;
    x_map[i].z = -0.25 * val_i;
    z_map[i].z = -0.25 * val_i;
    y_map[i].z = 0.5 * val_i;
}
}
