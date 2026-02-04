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
    for (; i <= (ssize_t)32767UL; i++) {
        MagickRealType temp = 1.099 * i - 0.099000000000000004;
        MagickRealType scaled_x = 0.29883900000000002 * temp;
        MagickRealType scaled_y = (-0.29883900000000002) * temp;
        MagickRealType scaled_z = 0.70099999999999996 * temp;
        MagickRealType scaled_yx = 0.58681099999999997 * temp;
        MagickRealType scaled_yy = (-0.58681099999999997) * temp;
        MagickRealType scaled_yz = (-0.58681099999999997) * temp;
        MagickRealType scaled_zx = 0.11434999999999999 * temp;
        MagickRealType scaled_zy = 0.88600000000000001 * temp;
        MagickRealType scaled_zz = (-0.11434999999999999) * temp;

        for (j = 0; j < 2; j++) {
            ssize_t idx = i * 2 + j;
            x_map[idx].x = scaled_x;
            x_map[idx].y = scaled_y;
            x_map[idx].z = scaled_z;
            y_map[idx].x = scaled_yx;
            y_map[idx].y = scaled_yy;
            y_map[idx].z = scaled_yz;
            z_map[idx].x = scaled_zx;
            z_map[idx].y = scaled_zy;
            z_map[idx].z = scaled_zz;
        }
    }
}
