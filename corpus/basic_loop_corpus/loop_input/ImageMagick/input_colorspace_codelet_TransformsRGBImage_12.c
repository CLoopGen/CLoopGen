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
    const size_t num_elements = 65536; // i from 0 to 65535 inclusive

    // Allocate memory for the arrays
    x_map = (TransformPacket*)calloc(num_elements, sizeof(TransformPacket));
    y_map = (TransformPacket*)calloc(num_elements, sizeof(TransformPacket));
    z_map = (TransformPacket*)calloc(num_elements, sizeof(TransformPacket));

    if (!x_map || !y_map || !z_map) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
}

void loop();