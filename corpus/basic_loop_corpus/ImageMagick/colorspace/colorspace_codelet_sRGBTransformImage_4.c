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
    x_map[i].x = (MagickRealType)(0.21265600000000001 * (double)i);
    x_map[i].y = (MagickRealType)(-0.11457199999999999 * (double)i);
    x_map[i].z = (MagickRealType)(0.5 * (double)i);
    y_map[i].x = (MagickRealType)(0.71515799999999996 * (double)i);
    y_map[i].y = (MagickRealType)(-0.38542799999999999 * (double)i);
    y_map[i].z = (MagickRealType)(-0.45415299999999997 * (double)i);
    z_map[i].x = (MagickRealType)(0.072186 * (double)i);
    z_map[i].y = (MagickRealType)(0.5 * (double)i);
    z_map[i].z = (MagickRealType)(-0.045846999999999999 * (double)i);
}

}
