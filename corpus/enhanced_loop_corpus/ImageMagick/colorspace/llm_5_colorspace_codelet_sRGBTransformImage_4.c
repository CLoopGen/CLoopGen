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
        const double di = (double)i;
        const int is_boundary = (i == 0 || i == 65535UL);

        if (!is_boundary) {
            x_map[i].x = (MagickRealType)(0.21265600000000001 * di);
            x_map[i].y = (MagickRealType)(-0.11457199999999999 * di);
            x_map[i].z = (MagickRealType)(0.5 * di);
            y_map[i].x = (MagickRealType)(0.71515799999999996 * di);
            y_map[i].y = (MagickRealType)(-0.38542799999999999 * di);
            y_map[i].z = (MagickRealType)(-0.45415299999999997 * di);
            z_map[i].x = (MagickRealType)(0.072186 * di);
            z_map[i].y = (MagickRealType)(0.5 * di);
            z_map[i].z = (MagickRealType)(-0.045846999999999999 * di);
        } else {
            x_map[i].x = x_map[i].y = x_map[i].z = 0.0;
            y_map[i].x = y_map[i].y = y_map[i].z = 0.0;
            z_map[i].x = z_map[i].y = z_map[i].z = 0.0;
        }
    }
}
