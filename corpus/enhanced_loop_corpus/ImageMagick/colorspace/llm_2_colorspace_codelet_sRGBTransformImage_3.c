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
for (i = 0; i <= (ssize_t)65535UL; i += 4) {
    ssize_t j1 = i;
    ssize_t j2 = i + 1;
    ssize_t j3 = i + 2;
    ssize_t j4 = i + 3;

    if (j1 <= (ssize_t)65535UL) {
        x_map[j1].x = (MagickRealType)(0.29883900000000002 * (double)j1);
        x_map[j1].y = (MagickRealType)(-0.16873669999999999 * (double)j1);
        x_map[j1].z = (MagickRealType)(0.5 * (double)j1);
        y_map[j1].x = (MagickRealType)(0.58681099999999997 * (double)j1);
        y_map[j1].y = (MagickRealType)(-0.331264 * (double)j1);
        y_map[j1].z = (MagickRealType)(-0.418688 * (double)j1);
        z_map[j1].x = (MagickRealType)(0.11434999999999999 * (double)j1);
        z_map[j1].y = (MagickRealType)(0.5 * (double)j1);
        z_map[j1].z = (MagickRealType)(-0.081311999999999995 * (double)j1);
    }
    if (j2 <= (ssize_t)65535UL) {
        x_map[j2].x = (MagickRealType)(0.29883900000000002 * (double)j2);
        x_map[j2].y = (MagickRealType)(-0.16873669999999999 * (double)j2);
        x_map[j2].z = (MagickRealType)(0.5 * (double)j2);
        y_map[j2].x = (MagickRealType)(0.58681099999999997 * (double)j2);
        y_map[j2].y = (MagickRealType)(-0.331264 * (double)j2);
        y_map[j2].z = (MagickRealType)(-0.418688 * (double)j2);
        z_map[j2].x = (MagickRealType)(0.11434999999999999 * (double)j2);
        z_map[j2].y = (MagickRealType)(0.5 * (double)j2);
        z_map[j2].z = (MagickRealType)(-0.081311999999999995 * (double)j2);
    }
    if (j3 <= (ssize_t)65535UL) {
        x_map[j3].x = (MagickRealType)(0.29883900000000002 * (double)j3);
        x_map[j3].y = (MagickRealType)(-0.16873669999999999 * (double)j3);
        x_map[j3].z = (MagickRealType)(0.5 * (double)j3);
        y_map[j3].x = (MagickRealType)(0.58681099999999997 * (double)j3);
        y_map[j3].y = (MagickRealType)(-0.331264 * (double)j3);
        y_map[j3].z = (MagickRealType)(-0.418688 * (double)j3);
        z_map[j3].x = (MagickRealType)(0.11434999999999999 * (double)j3);
        z_map[j3].y = (MagickRealType)(0.5 * (double)j3);
        z_map[j3].z = (MagickRealType)(-0.081311999999999995 * (double)j3);
    }
    if (j4 <= (ssize_t)65535UL) {
        x_map[j4].x = (MagickRealType)(0.29883900000000002 * (double)j4);
        x_map[j4].y = (MagickRealType)(-0.16873669999999999 * (double)j4);
        x_map[j4].z = (MagickRealType)(0.5 * (double)j4);
        y_map[j4].x = (MagickRealType)(0.58681099999999997 * (double)j4);
        y_map[j4].y = (MagickRealType)(-0.331264 * (double)j4);
        y_map[j4].z = (MagickRealType)(-0.418688 * (double)j4);
        z_map[j4].x = (MagickRealType)(0.11434999999999999 * (double)j4);
        z_map[j4].y = (MagickRealType)(0.5 * (double)j4);
        z_map[j4].z = (MagickRealType)(-0.081311999999999995 * (double)j4);
    }
}
}
