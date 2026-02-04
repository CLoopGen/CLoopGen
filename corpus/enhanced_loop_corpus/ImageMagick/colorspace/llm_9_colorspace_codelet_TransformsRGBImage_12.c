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
    MagickRealType idx = (MagickRealType)i;
    MagickRealType term = (MagickRealType)(2. * idx - 65535UL);
    MagickRealType scaled_term_x = 0.5 * 0. * term;
    MagickRealType scaled_term_y1 = 0.5 * (-0.18732399999999999) * term;
    MagickRealType scaled_term_z1 = 0.5 * 1.5748 * term;
    MagickRealType scaled_term_y2 = 0.5 * (-0.46812399999999998) * term;
    MagickRealType scaled_term_z2 = 0.5 * 1.8555999999999999 * term;
    MagickRealType scaled_term_y3 = 0.5 * 0. * term;

    x_map[i].x = idx;
    y_map[i].x = scaled_term_x;
    z_map[i].x = scaled_term_z1;
    x_map[i].y = idx;
    y_map[i].y = scaled_term_y1;
    z_map[i].y = scaled_term_y2;
    x_map[i].z = idx;
    y_map[i].z = scaled_term_z2;
    z_map[i].z = scaled_term_y3;

    if (i + 1 <= 65535UL) {
        idx = (MagickRealType)(i + 1);
        term = (MagickRealType)(2. * idx - 65535UL);

        x_map[i+1].x = idx;
        y_map[i+1].x = (MagickRealType)(0.5 * 0. * term);
        z_map[i+1].x = (MagickRealType)(0.5 * 1.5748 * term);
        x_map[i+1].y = idx;
        y_map[i+1].y = (MagickRealType)(0.5 * (-0.18732399999999999) * term);
        z_map[i+1].y = (MagickRealType)(0.5 * (-0.46812399999999998) * term);
        x_map[i+1].z = idx;
        y_map[i+1].z = (MagickRealType)(0.5 * 1.8555999999999999 * term);
        z_map[i+1].z = (MagickRealType)(0.5 * 0. * term);
    }
}
}
