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
    TransformPacket temp_x, temp_y, temp_z;
    for (i = 0; i <= (ssize_t)65535UL; i++) {
        MagickRealType scaled_i = (MagickRealType)(double)i;
        temp_x.x = 0.29883900000000002 * scaled_i;
        temp_x.y = -0.16873669999999999 * scaled_i;
        temp_x.z = 0.5 * scaled_i;
        temp_y.x = 0.58681099999999997 * scaled_i;
        temp_y.y = -0.331264 * scaled_i;
        temp_y.z = -0.418688 * scaled_i;
        temp_z.x = 0.11434999999999999 * scaled_i;
        temp_z.y = 0.5 * scaled_i;
        temp_z.z = -0.081311999999999995 * scaled_i;
        x_map[i] = temp_x;
        y_map[i] = temp_y;
        z_map[i] = temp_z;
    }
}
