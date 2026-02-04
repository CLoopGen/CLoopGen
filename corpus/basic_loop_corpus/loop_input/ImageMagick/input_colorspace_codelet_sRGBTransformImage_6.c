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

ssize_t i = 0;

#define DATA_SIZE 65536

TransformPacket *x_map;
TransformPacket *y_map;
TransformPacket *z_map;

void init_vars() {
    x_map = (TransformPacket*)calloc(DATA_SIZE, sizeof(TransformPacket));
    y_map = (TransformPacket*)calloc(DATA_SIZE, sizeof(TransformPacket));
    z_map = (TransformPacket*)calloc(DATA_SIZE, sizeof(TransformPacket));
    
    if (!x_map || !y_map || !z_map) {
        exit(1);
    }
}