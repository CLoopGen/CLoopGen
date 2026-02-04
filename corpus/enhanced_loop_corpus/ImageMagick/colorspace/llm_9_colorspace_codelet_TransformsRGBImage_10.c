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
const ssize_t stride = 4;
for (i = 0; i <= (ssize_t)65535UL; i += stride) {
    for (ssize_t j = 0; j < stride && (i + j) <= 65535UL; ++j) {
        ssize_t k = i + j;
        double dk = (double)k;
        double term = 2.0 * dk - 65535.0;

        x_map[k].x = (MagickRealType)(dk);
        y_map[k].x = (MagickRealType)(0.5 * 1.0 * term);
        z_map[k].x = (MagickRealType)(-0.5 * 0.66668000000000005 * term);

        x_map[k].y = (MagickRealType)(dk);
        y_map[k].y = 0.0;
        z_map[k].y = (MagickRealType)(0.5 * 1.3333299999999999 * term);

        x_map[k].z = (MagickRealType)(dk);
        y_map[k].z = (MagickRealType)(-0.5 * 1.0 * term);
        z_map[k].z = (MagickRealType)(-0.5 * 0.66668000000000005 * term);
    }
}
}
