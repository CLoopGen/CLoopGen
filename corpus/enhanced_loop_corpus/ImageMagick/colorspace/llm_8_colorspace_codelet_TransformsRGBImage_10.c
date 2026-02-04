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
extern TransformPacket *y_map;
extern TransformPacket *x_map;
extern TransformPacket *z_map;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= (ssize_t)65535UL; i += 2) {
    MagickRealType idx = (MagickRealType)(double)i;
    MagickRealType term = (MagickRealType)(2.0 * (double)i - 65535.0);
    MagickRealType c1 = (MagickRealType)(0.5 * 1.0 * term);
    MagickRealType c2 = (MagickRealType)(-0.5 * 0.66668000000000005 * term);
    MagickRealType c3 = (MagickRealType)(0.5 * 1.3333299999999999 * term);

    x_map[i].x = idx;
    y_map[i].x = c1;
    z_map[i].x = c2;
    x_map[i].y = idx;
    y_map[i].y = 0.0;
    z_map[i].y = c3;
    x_map[i].z = idx;
    y_map[i].z = -c1;
    z_map[i].z = c2;

    if (i + 1 <= 65535UL) {
        idx = (MagickRealType)(double)(i + 1);
        term = (MagickRealType)(2.0 * (double)(i + 1) - 65535.0);
        c1 = (MagickRealType)(0.5 * 1.0 * term);
        c2 = (MagickRealType)(-0.5 * 0.66668000000000005 * term);
        c3 = (MagickRealType)(0.5 * 1.3333299999999999 * term);

        x_map[i+1].x = idx;
        y_map[i+1].x = c1;
        z_map[i+1].x = c2;
        x_map[i+1].y = idx;
        y_map[i+1].y = 0.0;
        z_map[i+1].y = c3;
        x_map[i+1].z = idx;
        y_map[i+1].z = -c1;
        z_map[i+1].z = c2;
    }
}
}
