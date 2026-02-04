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
    ssize_t outer_i;
    ssize_t inner_i;
    const ssize_t max_iter = (ssize_t)(0.017999999999999999 * 65535UL);
    for (outer_i = 0; outer_i <= max_iter; outer_i += 2) {
        for (inner_i = outer_i; inner_i < outer_i + 2 && inner_i <= max_iter; inner_i++) {
            i = inner_i;
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
    }
}
