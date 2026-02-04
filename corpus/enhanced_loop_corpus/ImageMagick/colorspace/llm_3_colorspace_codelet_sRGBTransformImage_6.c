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
for (ssize_t idx = 0; idx <= (ssize_t)65535UL / 4; idx++) {
    for (ssize_t stride = 0; stride < 4; stride++) {
        ssize_t i = (idx * 4) + stride;
        if (i > (ssize_t)65535UL) continue;
        MagickRealType factor = 1.099 * i - 0.099000000000000004;
        x_map[i].x = 0.29883900000000002 * factor;
        x_map[i].y = (-0.29883900000000002) * factor;
        x_map[i].z = 0.70099999999999996 * factor;
        y_map[i].x = 0.58681099999999997 * factor;
        y_map[i].y = (-0.58681099999999997) * factor;
        y_map[i].z = (-0.58681099999999997) * factor;
        z_map[i].x = 0.11434999999999999 * factor;
        z_map[i].y = 0.88600000000000001 * factor;
        z_map[i].z = (-0.11434999999999999) * factor;
    }
}
}
