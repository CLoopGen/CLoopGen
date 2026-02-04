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
const ssize_t n = 65535UL / 2;
for (i = 0; i <= n; i++) {
    double temp_x = (double)i;
    double temp_scaled = 2.0 * temp_x - 32767.0;

    // Reduced precision constants and simplified expressions
    MagickRealType a = 1.0 * temp_x;
    MagickRealType b = 0.5 * (-1.22e-6) * temp_scaled;
    MagickRealType c = 0.5 * 1.402 * temp_scaled;

    x_map[i].x = a;
    y_map[i].x = b;
    z_map[i].x = c;
    x_map[i].y = a;
    y_map[i].y = b;
    z_map[i].y = c;
    x_map[i].z = a;
    y_map[i].z = b;
    z_map[i].z = c;
}
}
