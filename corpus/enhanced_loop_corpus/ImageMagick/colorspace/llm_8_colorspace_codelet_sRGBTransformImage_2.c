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
    MagickRealType factor1 = (MagickRealType)(0.33333000000000002 * (double)i);
    MagickRealType factor2 = (MagickRealType)(0.5 * (double)i);
    MagickRealType factor3 = (MagickRealType)(-0.25 * (double)i);
    MagickRealType factor4 = (MagickRealType)(0.33334000000000003 * (double)i);

    x_map[i].x = factor1;
    x_map[i].y = factor2;
    x_map[i].z = factor3;
    y_map[i].x = factor4;
    y_map[i].y = 0.0;
    y_map[i].z = factor2;
    z_map[i].x = factor1;
    z_map[i].y = -factor2;
    z_map[i].z = factor3;

    if (i + 1 <= 32767UL) {
        x_map[i+1].x = factor1 + (MagickRealType)(0.33333000000000002);
        x_map[i+1].y = factor2 + (MagickRealType)(0.5);
        x_map[i+1].z = factor3 - (MagickRealType)(0.25);
        y_map[i+1].x = factor4 + (MagickRealType)(0.33334000000000003);
        y_map[i+1].y = 0.0;
        y_map[i+1].z = factor2 + (MagickRealType)(0.5);
        z_map[i+1].x = factor1 + (MagickRealType)(0.33333000000000002);
        z_map[i+1].y = -factor2 - (MagickRealType)(0.5);
        z_map[i+1].z = factor3 - (MagickRealType)(0.25);
    }
}
}
