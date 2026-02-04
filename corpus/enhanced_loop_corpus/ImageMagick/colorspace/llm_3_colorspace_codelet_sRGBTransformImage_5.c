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
    ssize_t *indices = (ssize_t*)alloca((upper_bound + 1) * sizeof(ssize_t));
    for (ssize_t j = 0; j <= upper_bound; j++) {
        indices[j] = j;
    }
    for (ssize_t j = 0; j <= upper_bound; j++) {
        ssize_t idx = indices[j];
        x_map[idx].x = 0.0053819999999999996 * idx;
        x_map[idx].y = (-0.0032959999999999999) * idx;
        x_map[idx].z = 0.0094099999999999999 * idx;
        y_map[idx].x = 0.010566000000000001 * idx;
        y_map[idx].y = (-0.0064710000000000002) * idx;
        y_map[idx].z = (-0.0078799999999999998) * idx;
        z_map[idx].x = 0.002052 * idx;
        z_map[idx].y = 0.0097680000000000006 * idx;
        z_map[idx].z = (-0.0015299999999999999) * idx;
    }
}
