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
    ssize_t i1 = i;
    ssize_t i2 = i + 1;
    ssize_t i3 = i + 2;
    ssize_t i4 = i + 3;

    x_map[i1].x = (MagickRealType)(0.21265600000000001 * (double)i1);
    x_map[i1].y = (MagickRealType)(-0.11457199999999999 * (double)i1);
    x_map[i1].z = (MagickRealType)(0.5 * (double)i1);
    y_map[i1].x = (MagickRealType)(0.71515799999999996 * (double)i1);
    y_map[i1].y = (MagickRealType)(-0.38542799999999999 * (double)i1);
    y_map[i1].z = (MagickRealType)(-0.45415299999999997 * (double)i1);
    z_map[i1].x = (MagickRealType)(0.072186 * (double)i1);
    z_map[i1].y = (MagickRealType)(0.5 * (double)i1);
    z_map[i1].z = (MagickRealType)(-0.045846999999999999 * (double)i1);

    if (i2 <= (ssize_t)65535UL) {
        x_map[i2].x = (MagickRealType)(0.21265600000000001 * (double)i2);
        x_map[i2].y = (MagickRealType)(-0.11457199999999999 * (double)i2);
        x_map[i2].z = (MagickRealType)(0.5 * (double)i2);
        y_map[i2].x = (MagickRealType)(0.71515799999999996 * (double)i2);
        y_map[i2].y = (MagickRealType)(-0.38542799999999999 * (double)i2);
        y_map[i2].z = (MagickRealType)(-0.45415299999999997 * (double)i2);
        z_map[i2].x = (MagickRealType)(0.072186 * (double)i2);
        z_map[i2].y = (MagickRealType)(0.5 * (double)i2);
        z_map[i2].z = (MagickRealType)(-0.045846999999999999 * (double)i2);
    }

    if (i3 <= (ssize_t)65535UL) {
        x_map[i3].x = (MagickRealType)(0.21265600000000001 * (double)i3);
        x_map[i3].y = (MagickRealType)(-0.11457199999999999 * (double)i3);
        x_map[i3].z = (MagickRealType)(0.5 * (double)i3);
        y_map[i3].x = (MagickRealType)(0.71515799999999996 * (double)i3);
        y_map[i3].y = (MagickRealType)(-0.38542799999999999 * (double)i3);
        y_map[i3].z = (MagickRealType)(-0.45415299999999997 * (double)i3);
        z_map[i3].x = (MagickRealType)(0.072186 * (double)i3);
        z_map[i3].y = (MagickRealType)(0.5 * (double)i3);
        z_map[i3].z = (MagickRealType)(-0.045846999999999999 * (double)i3);
    }

    if (i4 <= (ssize_t)65535UL) {
        x_map[i4].x = (MagickRealType)(0.21265600000000001 * (double)i4);
        x_map[i4].y = (MagickRealType)(-0.11457199999999999 * (double)i4);
        x_map[i4].z = (MagickRealType)(0.5 * (double)i4);
        y_map[i4].x = (MagickRealType)(0.71515799999999996 * (double)i4);
        y_map[i4].y = (MagickRealType)(-0.38542799999999999 * (double)i4);
        y_map[i4].z = (MagickRealType)(-0.45415299999999997 * (double)i4);
        z_map[i4].x = (MagickRealType)(0.072186 * (double)i4);
        z_map[i4].y = (MagickRealType)(0.5 * (double)i4);
        z_map[i4].z = (MagickRealType)(-0.045846999999999999 * (double)i4);
    }
}
}
