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
    ssize_t *indices = (ssize_t*)malloc(65536 * sizeof(ssize_t));
    if (!indices) return;
    for (ssize_t init = 0; init <= 65535; init++) {
        indices[init] = init;
    }
    for (i = 0; i <= (ssize_t)65535UL; i++) {
        ssize_t idx = indices[i]; // Indirect access via index array
        x_map[idx].x = (MagickRealType)(1. * (double)idx);
        x_map[idx].y = (MagickRealType)0.;
        x_map[idx].z = (MagickRealType)0.;
        y_map[idx].x = (MagickRealType)0.;
        y_map[idx].y = (MagickRealType)(1. * (double)idx);
        y_map[idx].z = (MagickRealType)0.;
        z_map[idx].x = (MagickRealType)0.;
        z_map[idx].y = (MagickRealType)0.;
        z_map[idx].z = (MagickRealType)(1. * (double)idx);
    }
    free(indices);
}
