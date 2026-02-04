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
    // Variant 1: Consecutive memory access using array indexing with stride of 2 (strided access)
    // Access every second element in forward direction, then complete the pass in a second iteration
    ssize_t n = 65535UL;
    for (i = 0; i <= n; i += 2) {
        x_map[i].x = 0.99999999999914679 * (double)i;
        y_map[i].x = 0.5 * (-1.2188941887145875E-6) * (2. * (double)i - 65535UL);
        z_map[i].x = 0.5 * 1.401999588656144 * (2. * (double)i - 65535UL);
        x_map[i].y = 0.99999975910502514 * (double)i;
        y_map[i].y = 0.5 * (-0.34413567816504304) * (2. * (double)i - 65535UL);
        z_map[i].y = 0.5 * (-0.71413649331646789) * (2. * (double)i - 65535UL);
        x_map[i].z = 1.0000012404000462 * (double)i;
        y_map[i].z = 0.5 * 1.7720000660723041 * (2. * (double)i - 65535UL);
        z_map[i].z = 0.5 * 2.1453384174593273E-6 * (2. * (double)i - 65535UL);
    }
    for (i = 1; i <= n; i += 2) {
        x_map[i].x = 0.99999999999914679 * (double)i;
        y_map[i].x = 0.5 * (-1.2188941887145875E-6) * (2. * (double)i - 65535UL);
        z_map[i].x = 0.5 * 1.401999588656144 * (2. * (double)i - 65535UL);
        x_map[i].y = 0.99999975910502514 * (double)i;
        y_map[i].y = 0.5 * (-0.34413567816504304) * (2. * (double)i - 65535UL);
        z_map[i].y = 0.5 * (-0.71413649331646789) * (2. * (double)i - 65535UL);
        x_map[i].z = 1.0000012404000462 * (double)i;
        y_map[i].z = 0.5 * 1.7720000660723041 * (2. * (double)i - 65535UL);
        z_map[i].z = 0.5 * 2.1453384174593273E-6 * (2. * (double)i - 65535UL);
    }
}
