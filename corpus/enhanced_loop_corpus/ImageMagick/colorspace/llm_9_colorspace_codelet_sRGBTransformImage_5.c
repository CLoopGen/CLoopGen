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
    // Variant 2: Reduced trip count but increased per-element computation by applying a quadratic scaling
    // and introducing auxiliary computations to increase arithmetic intensity.
    const ssize_t reduced_bound = (ssize_t)(0.017999999999999999 * 65535UL / 3); // ~1/3 the original iterations

    for (i = 0; i <= reduced_bound; i++) {
        // Introduce intermediate computed values to increase arithmetic operations
        MagickRealType scale1 = 0.0053819999999999996 * i;
        MagickRealType scale2 = (-0.0032959999999999999) * i;
        MagickRealType scale3 = 0.0094099999999999999 * i;
        MagickRealType scale4 = 0.010566000000000001 * i;
        MagickRealType scale5 = (-0.0064710000000000002) * i;
        MagickRealType scale6 = (-0.0078799999999999998) * i;
        MagickRealType scale7 = 0.002052 * i;
        MagickRealType scale8 = 0.0097680000000000006 * i;
        MagickRealType scale9 = (-0.0015299999999999999) * i;

        // Additional non-linear transformations to increase computational load
        MagickRealType offset_x = scale1 * scale1 * 1e-4;
        MagickRealType offset_y = scale8 * scale8 * 1e-4;
        MagickRealType offset_z = scale6 * scale6 * 1e-4;

        x_map[i].x = scale1 + offset_x;
        x_map[i].y = scale2 - offset_y;
        x_map[i].z = scale3 + offset_z;
        y_map[i].x = scale4 + offset_y;
        y_map[i].y = scale5 - offset_z;
        y_map[i].z = scale6 + offset_x;
        z_map[i].x = scale7 + offset_z;
        z_map[i].y = scale8 - offset_x;
        z_map[i].z = scale9 + offset_y;
    }
}
