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

ssize_t i;
TransformPacket *y_map;
TransformPacket *x_map;
TransformPacket *z_map;

void init_vars() {
    const size_t array_size = 65536;
    const size_t total_bytes = array_size * sizeof(TransformPacket);

    x_map = aligned_alloc(32, total_bytes);
    y_map = aligned_alloc(32, total_bytes);
    z_map = aligned_alloc(32, total_bytes);

    if (!x_map || !y_map || !z_map) {
        exit(1);
    }

    for (size_t idx = 0; idx < array_size; idx++) {
        x_map[idx].x = 0.0;
        x_map[idx].y = 0.0;
        x_map[idx].z = 0.0;
        y_map[idx].x = 0.0;
        y_map[idx].y = 0.0;
        y_map[idx].z = 0.0;
        z_map[idx].x = 0.0;
        z_map[idx].y = 0.0;
        z_map[idx].z = 0.0;
    }
}