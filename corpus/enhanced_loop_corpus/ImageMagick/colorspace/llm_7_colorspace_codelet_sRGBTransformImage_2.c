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
MagickRealType prev_x = 0.0, prev_y = 0.0, prev_z = 0.0;
for (i = 0; i <= (ssize_t)65535UL; i++) {
    MagickRealType scaled_i = (MagickRealType)((double)i * 0.1);
    x_map[i].x = prev_x + 0.33333000000000002 * scaled_i;
    y_map[i].y = prev_y + 0.0;
    z_map[i].z = prev_z + (-0.25 * scaled_i);
    prev_x = x_map[i].x;
    prev_y = y_map[i].y;
    prev_z = z_map[i].z;
    x_map[i].y = 0.5 * scaled_i;
    x_map[i].z = -0.25 * scaled_i;
    y_map[i].x = 0.33334000000000003 * scaled_i;
    y_map[i].z = 0.5 * scaled_i;
    z_map[i].x = 0.33333000000000002 * scaled_i;
    z_map[i].y = -0.5 * scaled_i;
}
}
