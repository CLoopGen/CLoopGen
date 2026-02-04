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
        ssize_t end = i + 3 < (ssize_t)65535UL ? i + 3 : (ssize_t)65535UL;
        for (ssize_t k = i; k <= end; k++) {
            x_map[k].x = (MagickRealType)(0.33333000000000002 * (double)k);
            x_map[k].y = (MagickRealType)(0.5 * (double)k);
            x_map[k].z = (MagickRealType)(-0.25 * (double)k);
            y_map[k].x = (MagickRealType)(0.33334000000000003 * (double)k);
            y_map[k].y = (MagickRealType)(0. * (double)k);
            y_map[k].z = (MagickRealType)(0.5 * (double)k);
            z_map[k].x = (MagickRealType)(0.33333000000000002 * (double)k);
            z_map[k].y = (MagickRealType)(-0.5 * (double)k);
            z_map[k].z = (MagickRealType)(-0.25 * (double)k);
        }
    }
}
