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
    const size_t N = 65536; // Match loop bound: i <= 65535 -> 65536 elements
    const size_t data_size = N * sizeof(TransformPacket); // ~1.5MB per array, total ~4.5MB

    x_map = (TransformPacket*)aligned_alloc(32, data_size);
    y_map = (TransformPacket*)aligned_alloc(32, data_size);
    z_map = (TransformPacket*)aligned_alloc(32, data_size);

    if (!x_map || !y_map || !z_map) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < N; ++idx) {
        x_map[idx] = (TransformPacket){0.0, 0.0, 0.0};
        y_map[idx] = (TransformPacket){0.0, 0.0, 0.0};
        z_map[idx] = (TransformPacket){0.0, 0.0, 0.0};
    }
}