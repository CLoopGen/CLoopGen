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
    for (j = 0; j <= 255; j++) {
        for (i = j * 256; i <= (j * 256) + 255 && i <= (ssize_t)65535UL; i++) {
            x_map[i].x = (MagickRealType)(0.33333000000000002 * (double)i);
            x_map[i].y = (MagickRealType)(0.5 * (double)i);
            x_map[i].z = (MagickRealType)(-0.25 * (double)i);
            y_map[i].x = (MagickRealType)(0.33334000000000003 * (double)i);
            y_map[i].y = (MagickRealType)(0. * (double)i);
            y_map[i].z = (MagickRealType)(0.5 * (double)i);
            z_map[i].x = (MagickRealType)(0.33333000000000002 * (double)i);
            z_map[i].y = (MagickRealType)(-0.5 * (double)i);
            z_map[i].z = (MagickRealType)(-0.25 * (double)i);
        }
    }
}
