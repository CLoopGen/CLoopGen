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
    const MagickRealType val = (MagickRealType)(double)i;
    const MagickRealType factor = (i < 32768) ? 1.0 : -1.0;

    x_map[i].x = factor * (MagickRealType)(0.29883900000000002 * val);
    x_map[i].y = factor * (MagickRealType)(-0.16873669999999999 * val);
    x_map[i].z = factor * (MagickRealType)(0.5 * val);

    if (i >= 16384 && i < 49152) {
        y_map[i].x = (MagickRealType)(0.58681099999999997 * val);
        y_map[i].y = (MagickRealType)(-0.331264 * val);
        y_map[i].z = (MagickRealType)(-0.418688 * val);
    } else {
        y_map[i] = x_map[i];
    }

    z_map[i].x = factor * (MagickRealType)(0.11434999999999999 * val);
    z_map[i].y = factor * (MagickRealType)(0.5 * val);
    z_map[i].z = factor * (MagickRealType)(-0.081311999999999995 * val);
}
}
