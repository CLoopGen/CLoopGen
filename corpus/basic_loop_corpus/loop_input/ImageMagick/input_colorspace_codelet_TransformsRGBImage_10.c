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
    const size_t N = 65536;
    const size_t total_bytes = N * sizeof(TransformPacket);
    
    x_map = (TransformPacket*)calloc(N, sizeof(TransformPacket));
    y_map = (TransformPacket*)calloc(N, sizeof(TransformPacket));
    z_map = (TransformPacket*)calloc(N, sizeof(TransformPacket));
    
    if (!x_map || !y_map || !z_map) {
        exit(1);
    }
}