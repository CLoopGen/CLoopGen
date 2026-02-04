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
        MagickRealType val = (MagickRealType)(double)i;
        x_map[i].x = 0.29883900000000002 * val;
        y_map[i].x = 0.58681099999999997 * val;
        z_map[i].x = 0.11434999999999999 * val;
        x_map[i].y = -0.16873669999999999 * val;
        y_map[i].y = -0.331264 * val;
        z_map[i].y = 0.5 * val;
        x_map[i].z = 0.5 * val;
        y_map[i].z = -0.418688 * val;
        z_map[i].z = -0.081311999999999995 * val;
    }
}
