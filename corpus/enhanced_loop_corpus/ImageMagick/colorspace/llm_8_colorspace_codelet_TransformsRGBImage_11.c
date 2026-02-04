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
for (i = 0; i <= (ssize_t)65535UL; i += 4) {
    x_map[i].x = 0.99999999999914679 * (double)i;
    y_map[i].x = 0.5 * (-1.2188941887145875E-6) * (2. * (double)i - 65535UL);
    z_map[i].x = 0.5 * 1.401999588656144 * (2. * (double)i - 65535UL);
    x_map[i].y = 0.99999975910502514 * (double)i;
    y_map[i].y = 0.5 * (-0.34413567816504304) * (2. * (double)i - 65535UL);
    z_map[i].y = 0.5 * (-0.71413649331646789) * (2. * (double)i - 65535UL);
    x_map[i].z = 1.0000012404000462 * (double)i;
    y_map[i].z = 0.5 * 1.7720000660723041 * (2. * (double)i - 65535UL);
    z_map[i].z = 0.5 * 2.1453384174593273E-6 * (2. * (double)i - 65535UL);

    if (i + 1 <= 65535UL) {
        x_map[i+1].x = 0.99999999999914679 * (double)(i+1);
        y_map[i+1].x = 0.5 * (-1.2188941887145875E-6) * (2. * (double)(i+1) - 65535UL);
        z_map[i+1].x = 0.5 * 1.401999588656144 * (2. * (double)(i+1) - 65535UL);
        x_map[i+1].y = 0.99999975910502514 * (double)(i+1);
        y_map[i+1].y = 0.5 * (-0.34413567816504304) * (2. * (double)(i+1) - 65535UL);
        z_map[i+1].y = 0.5 * (-0.71413649331646789) * (2. * (double)(i+1) - 65535UL);
        x_map[i+1].z = 1.0000012404000462 * (double)(i+1);
        y_map[i+1].z = 0.5 * 1.7720000660723041 * (2. * (double)(i+1) - 65535UL);
        z_map[i+1].z = 0.5 * 2.1453384174593273E-6 * (2. * (double)(i+1) - 65535UL);
    }

    if (i + 2 <= 65535UL) {
        x_map[i+2].x = 0.99999999999914679 * (double)(i+2);
        y_map[i+2].x = 0.5 * (-1.2188941887145875E-6) * (2. * (double)(i+2) - 65535UL);
        z_map[i+2].x = 0.5 * 1.401999588656144 * (2. * (double)(i+2) - 65535UL);
        x_map[i+2].y = 0.99999975910502514 * (double)(i+2);
        y_map[i+2].y = 0.5 * (-0.34413567816504304) * (2. * (double)(i+2) - 65535UL);
        z_map[i+2].y = 0.5 * (-0.71413649331646789) * (2. * (double)(i+2) - 65535UL);
        x_map[i+2].z = 1.0000012404000462 * (double)(i+2);
        y_map[i+2].z = 0.5 * 1.7720000660723041 * (2. * (double)(i+2) - 65535UL);
        z_map[i+2].z = 0.5 * 2.1453384174593273E-6 * (2. * (double)(i+2) - 65535UL);
    }

    if (i + 3 <= 65535UL) {
        x_map[i+3].x = 0.99999999999914679 * (double)(i+3);
        y_map[i+3].x = 0.5 * (-1.2188941887145875E-6) * (2. * (double)(i+3) - 65535UL);
        z_map[i+3].x = 0.5 * 1.401999588656144 * (2. * (double)(i+3) - 65535UL);
        x_map[i+3].y = 0.99999975910502514 * (double)(i+3);
        y_map[i+3].y = 0.5 * (-0.34413567816504304) * (2. * (double)(i+3) - 65535UL);
        z_map[i+3].y = 0.5 * (-0.71413649331646789) * (2. * (double)(i+3) - 65535UL);
        x_map[i+3].z = 1.0000012404000462 * (double)(i+3);
        y_map[i+3].z = 0.5 * 1.7720000660723041 * (2. * (double)(i+3) - 65535UL);
        z_map[i+3].z = 0.5 * 2.1453384174593273E-6 * (2. * (double)(i+3) - 65535UL);
    }
}
}
