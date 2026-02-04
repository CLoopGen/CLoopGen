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
    ssize_t j;
    for (j = 0; j <= (ssize_t)65535UL; j += 4) {
        ssize_t k1 = j;
        ssize_t k2 = j + 1;
        ssize_t k3 = j + 2;
        ssize_t k4 = j + 3;

        if (k1 <= 65535) {
            x_map[k1].x = (MagickRealType)(0.21265600000000001 * (double)k1);
            x_map[k1].y = (MagickRealType)(-0.11457199999999999 * (double)k1);
            x_map[k1].z = (MagickRealType)(0.5 * (double)k1);
            y_map[k1].x = (MagickRealType)(0.71515799999999996 * (double)k1);
            y_map[k1].y = (MagickRealType)(-0.38542799999999999 * (double)k1);
            y_map[k1].z = (MagickRealType)(-0.45415299999999997 * (double)k1);
            z_map[k1].x = (MagickRealType)(0.072186 * (double)k1);
            z_map[k1].y = (MagickRealType)(0.5 * (double)k1);
            z_map[k1].z = (MagickRealType)(-0.045846999999999999 * (double)k1);
        }
        if (k2 <= 65535) {
            x_map[k2].x = (MagickRealType)(0.21265600000000001 * (double)k2);
            x_map[k2].y = (MagickRealType)(-0.11457199999999999 * (double)k2);
            x_map[k2].z = (MagickRealType)(0.5 * (double)k2);
            y_map[k2].x = (MagickRealType)(0.71515799999999996 * (double)k2);
            y_map[k2].y = (MagickRealType)(-0.38542799999999999 * (double)k2);
            y_map[k2].z = (MagickRealType)(-0.45415299999999997 * (double)k2);
            z_map[k2].x = (MagickRealType)(0.072186 * (double)k2);
            z_map[k2].y = (MagickRealType)(0.5 * (double)k2);
            z_map[k2].z = (MagickRealType)(-0.045846999999999999 * (double)k2);
        }
        if (k3 <= 65535) {
            x_map[k3].x = (MagickRealType)(0.21265600000000001 * (double)k3);
            x_map[k3].y = (MagickRealType)(-0.11457199999999999 * (double)k3);
            x_map[k3].z = (MagickRealType)(0.5 * (double)k3);
            y_map[k3].x = (MagickRealType)(0.71515799999999996 * (double)k3);
            y_map[k3].y = (MagickRealType)(-0.38542799999999999 * (double)k3);
            y_map[k3].z = (MagickRealType)(-0.45415299999999997 * (double)k3);
            z_map[k3].x = (MagickRealType)(0.072186 * (double)k3);
            z_map[k3].y = (MagickRealType)(0.5 * (double)k3);
            z_map[k3].z = (MagickRealType)(-0.045846999999999999 * (double)k3);
        }
        if (k4 <= 65535) {
            x_map[k4].x = (MagickRealType)(0.21265600000000001 * (double)k4);
            x_map[k4].y = (MagickRealType)(-0.11457199999999999 * (double)k4);
            x_map[k4].z = (MagickRealType)(0.5 * (double)k4);
            y_map[k4].x = (MagickRealType)(0.71515799999999996 * (double)k4);
            y_map[k4].y = (MagickRealType)(-0.38542799999999999 * (double)k4);
            y_map[k4].z = (MagickRealType)(-0.45415299999999997 * (double)k4);
            z_map[k4].x = (MagickRealType)(0.072186 * (double)k4);
            z_map[k4].y = (MagickRealType)(0.5 * (double)k4);
            z_map[k4].z = (MagickRealType)(-0.045846999999999999 * (double)k4);
        }
    }
}
