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
for (i = 0; i <= (ssize_t)65535UL; i++) {
    const MagickRealType temp = (MagickRealType)(2. * i - 65535UL);
    const MagickRealType factor_y = 0.5 * (-0.18732399999999999) * temp;
    const MagickRealType factor_z_y = 0.5 * (-0.46812399999999998) * temp;
    
    x_map[i].x = (MagickRealType)(1. * i);
    y_map[i].x = 0.0;
    z_map[i].x = (MagickRealType)(0.5 * 1.5748 * temp);

    if (i != 0) {
        x_map[i].y = (MagickRealType)(1. * i);
        if (i & 1) {
            y_map[i].y = factor_y;
            z_map[i].y = factor_z_y;
        } else {
            y_map[i].y = -factor_y;
            z_map[i].y = -factor_z_y;
        }
    } else {
        x_map[i].y = 0.0;
        y_map[i].y = 0.0;
        z_map[i].y = 0.0;
    }

    x_map[i].z = (MagickRealType)(1. * i);
    y_map[i].z = (MagickRealType)(0.5 * 1.8555999999999999 * temp);
    z_map[i].z = 0.0;
}
}
