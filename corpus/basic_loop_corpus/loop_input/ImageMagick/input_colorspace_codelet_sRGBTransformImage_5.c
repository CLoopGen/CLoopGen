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
TransformPacket *x_map;
TransformPacket *y_map;
TransformPacket *z_map;

void init_vars() {
    const ssize_t N = (ssize_t)(0.017999999999999999 * 65535UL) + 1;
    
    x_map = (TransformPacket*)calloc(N, sizeof(TransformPacket));
    y_map = (TransformPacket*)calloc(N, sizeof(TransformPacket));
    z_map = (TransformPacket*)calloc(N, sizeof(TransformPacket));
    
    if (!x_map || !y_map || !z_map) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}