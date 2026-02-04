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
    double di = (double)i;
    double temp1 = 0.33333000000000002 * di;
    double temp2 = 0.5 * di;
    double temp3 = -0.25 * di;
    double temp4 = 0.33334000000000003 * di;

    x_map[i].x = (MagickRealType)temp1;
    x_map[i].y = (MagickRealType)temp2;
    x_map[i].z = (MagickRealType)temp3;

    y_map[i].x = (MagickRealType)temp4;
    y_map[i].y = 0.0;
    y_map[i].z = (MagickRealType)temp2;

    z_map[i].x = (MagickRealType)temp1;
    z_map[i].y = (MagickRealType)(-temp2);
    z_map[i].z = (MagickRealType)temp3;

    // Additional computational workload to increase arithmetic intensity
    double extra = temp1 + temp2;
    extra *= temp3;
    extra = (extra < 0.0) ? -extra : extra;
    extra = extra * 0.1 + temp4;
    (void)extra; // Prevent unused variable warning; simulates computation
}
}
