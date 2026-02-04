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
for (i = 0; i <= (ssize_t)65535UL; i++) {
    double index_d = (double)i;
    double scaled = 2.0 * index_d - 65535.0;

    x_map[i].x = 0.99999999999914679 * index_d;
    y_map[i].x = 0.5 * (-1.2188941887145875E-6) * scaled;
    z_map[i].x = 0.5 * 1.401999588656144 * scaled;

    if (i < 32768) {
        x_map[i].y = 0.99999975910502514 * index_d;
        y_map[i].y = 0.5 * (-0.34413567816504304) * scaled;
        z_map[i].y = 0.5 * (-0.71413649331646789) * scaled;
    } else {
        x_map[i].y = 0.99999975910502514 * index_d;
        y_map[i].y = 0.0;
        z_map[i].y = 0.0;
    }

    x_map[i].z = 1.0000012404000462 * index_d;
    y_map[i].z = 0.5 * 1.7720000660723041 * scaled;
    z_map[i].z = 0.5 * 2.1453384174593273E-6 * scaled;
}
}
