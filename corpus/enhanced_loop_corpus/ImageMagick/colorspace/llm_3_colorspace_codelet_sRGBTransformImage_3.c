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
ssize_t indices[65536];
for (ssize_t temp = 0; temp <= 65535; temp++) {
    indices[temp] = temp;
}

for (i = 0; i <= (ssize_t)65535UL; i++) {
    ssize_t idx = indices[i]; // Indirect access via lookup table

    x_map[idx].x = (MagickRealType)(0.29883900000000002 * (double)idx);
    x_map[idx].y = (MagickRealType)(-0.16873669999999999 * (double)idx);
    x_map[idx].z = (MagickRealType)(0.5 * (double)idx);
    y_map[idx].x = (MagickRealType)(0.58681099999999997 * (double)idx);
    y_map[idx].y = (MagickRealType)(-0.331264 * (double)idx);
    y_map[idx].z = (MagickRealType)(-0.418688 * (double)idx);
    z_map[idx].x = (MagickRealType)(0.11434999999999999 * (double)idx);
    z_map[idx].y = (MagickRealType)(0.5 * (double)idx);
    z_map[idx].z = (MagickRealType)(-0.081311999999999995 * (double)idx);
}
}
