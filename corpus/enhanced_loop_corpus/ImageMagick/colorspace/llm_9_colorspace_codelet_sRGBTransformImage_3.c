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
    MagickRealType scaled_i = (MagickRealType)(0.1 * (double)i);
    MagickRealType temp1 = scaled_i * 0.29883900000000002;
    MagickRealType temp2 = scaled_i * (-0.16873669999999999);
    MagickRealType temp3 = scaled_i * 0.5;
    MagickRealType temp4 = scaled_i * 0.58681099999999997;
    MagickRealType temp5 = scaled_i * (-0.331264);
    MagickRealType temp6 = scaled_i * (-0.418688);
    MagickRealType temp7 = scaled_i * 0.11434999999999999;
    MagickRealType temp8 = scaled_i * 0.5;
    MagickRealType temp9 = scaled_i * (-0.081311999999999995);

    x_map[i].x = temp1;
    x_map[i].y = temp2;
    x_map[i].z = temp3;
    y_map[i].x = temp4;
    y_map[i].y = temp5;
    y_map[i].z = temp6;
    z_map[i].x = temp7;
    z_map[i].y = temp8;
    z_map[i].z = temp9;
}
}
