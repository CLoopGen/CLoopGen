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
MagickRealType base_val = (MagickRealType)(-0.5 * 0.66668000000000005 * (2. * 65535UL));
for (i = 0; i <= (ssize_t)65535UL; i++) {
    MagickRealType scaled_i = (MagickRealType)(1. * (double)i);
    MagickRealType linear_term = (MagickRealType)(2. * (double)i);

    x_map[i].x = scaled_i;
    x_map[i].y = scaled_i;
    x_map[i].z = scaled_i;

    y_map[i].x = (MagickRealType)(0.5 * 1. * (linear_term - 65535UL));
    y_map[i].y = 0.0;
    y_map[i].z = (MagickRealType)(-0.5 * 1. * (linear_term - 65535UL));

    z_map[i].x = base_val + (MagickRealType)(0.66668000000000005 * linear_term * 0.5);
    z_map[i].y = (MagickRealType)(0.5 * 1.3333299999999999 * (linear_term - 65535UL));
    z_map[i].z = base_val + (MagickRealType)(0.66668000000000005 * linear_term * 0.5);
}
}
