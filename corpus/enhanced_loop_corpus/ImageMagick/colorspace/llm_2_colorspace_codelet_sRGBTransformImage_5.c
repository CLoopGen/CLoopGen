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
    ssize_t upper_bound = (ssize_t)(0.017999999999999999 * 65535UL);
    for (i = 0; i <= upper_bound; i += 3) {
        if (i + 0 <= upper_bound) {
            x_map[i].x = 0.0053819999999999996 * i;
            x_map[i].y = (-0.0032959999999999999) * i;
            x_map[i].z = 0.0094099999999999999 * i;
            y_map[i].x = 0.010566000000000001 * i;
            y_map[i].y = (-0.0064710000000000002) * i;
            y_map[i].z = (-0.0078799999999999998) * i;
            z_map[i].x = 0.002052 * i;
            z_map[i].y = 0.0097680000000000006 * i;
            z_map[i].z = (-0.0015299999999999999) * i;
        }
        if (i + 1 <= upper_bound) {
            x_map[i+1].x = 0.0053819999999999996 * (i+1);
            x_map[i+1].y = (-0.0032959999999999999) * (i+1);
            x_map[i+1].z = 0.0094099999999999999 * (i+1);
            y_map[i+1].x = 0.010566000000000001 * (i+1);
            y_map[i+1].y = (-0.0064710000000000002) * (i+1);
            y_map[i+1].z = (-0.0078799999999999998) * (i+1);
            z_map[i+1].x = 0.002052 * (i+1);
            z_map[i+1].y = 0.0097680000000000006 * (i+1);
            z_map[i+1].z = (-0.0015299999999999999) * (i+1);
        }
        if (i + 2 <= upper_bound) {
            x_map[i+2].x = 0.0053819999999999996 * (i+2);
            x_map[i+2].y = (-0.0032959999999999999) * (i+2);
            x_map[i+2].z = 0.0094099999999999999 * (i+2);
            y_map[i+2].x = 0.010566000000000001 * (i+2);
            y_map[i+2].y = (-0.0064710000000000002) * (i+2);
            y_map[i+2].z = (-0.0078799999999999998) * (i+2);
            z_map[i+2].x = 0.002052 * (i+2);
            z_map[i+2].y = 0.0097680000000000006 * (i+2);
            z_map[i+2].z = (-0.0015299999999999999) * (i+2);
        }
    }
}
