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
    ssize_t indices[4] = {0, 16384, 32768, 49152}; // Strided access pattern: every quarter of the range
    for (ssize_t s = 0; s < 4; s++) {
        ssize_t base = indices[s];
        for (ssize_t i_offset = 0; i_offset < 16384 && (base + i_offset) <= 65535; i_offset++) {
            ssize_t idx = base + i_offset;
            x_map[idx].x = (MagickRealType)(0.21265600000000001 * (double)idx);
            x_map[idx].y = (MagickRealType)(-0.11457199999999999 * (double)idx);
            x_map[idx].z = (MagickRealType)(0.5 * (double)idx);
            y_map[idx].x = (MagickRealType)(0.71515799999999996 * (double)idx);
            y_map[idx].y = (MagickRealType)(-0.38542799999999999 * (double)idx);
            y_map[idx].z = (MagickRealType)(-0.45415299999999997 * (double)idx);
            z_map[idx].x = (MagickRealType)(0.072186 * (double)idx);
            z_map[idx].y = (MagickRealType)(0.5 * (double)idx);
            z_map[idx].z = (MagickRealType)(-0.045846999999999999 * (double)idx);
        }
    }
}
