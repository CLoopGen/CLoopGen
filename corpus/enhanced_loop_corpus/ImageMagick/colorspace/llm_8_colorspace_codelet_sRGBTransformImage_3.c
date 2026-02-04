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
for (i = 0; i <= (ssize_t)32767UL; i += 2) {
    MagickRealType idx = (MagickRealType)(double)i;
    MagickRealType idx2 = (MagickRealType)(double)(i + 1);

    x_map[i].x = (MagickRealType)(0.29883900000000002 * idx);
    x_map[i].y = (MagickRealType)(-0.16873669999999999 * idx);
    x_map[i].z = (MagickRealType)(0.5 * idx);
    y_map[i].x = (MagickRealType)(0.58681099999999997 * idx);
    y_map[i].y = (MagickRealType)(-0.331264 * idx);
    y_map[i].z = (MagickRealType)(-0.418688 * idx);
    z_map[i].x = (MagickRealType)(0.11434999999999999 * idx);
    z_map[i].y = (MagickRealType)(0.5 * idx);
    z_map[i].z = (MagickRealType)(-0.081311999999999995 * idx);

    if (i + 1 <= (ssize_t)65535UL) {
        x_map[i+1].x = (MagickRealType)(0.29883900000000002 * idx2);
        x_map[i+1].y = (MagickRealType)(-0.16873669999999999 * idx2);
        x_map[i+1].z = (MagickRealType)(0.5 * idx2);
        y_map[i+1].x = (MagickRealType)(0.58681099999999997 * idx2);
        y_map[i+1].y = (MagickRealType)(-0.331264 * idx2);
        y_map[i+1].z = (MagickRealType)(-0.418688 * idx2);
        z_map[i+1].x = (MagickRealType)(0.11434999999999999 * idx2);
        z_map[i+1].y = (MagickRealType)(0.5 * idx2);
        z_map[i+1].z = (MagickRealType)(-0.081311999999999995 * idx2);
    }
}
}
