#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Transposed Reference Offsets
    // Change access pattern to use variable-based offsets that simulate transposition.
    // This variant uses indirect indexing via precomputed offset arrays to simulate irregular access.

    int offsets_dst[12];
    int offsets_src[4];

    // Precompute destination offsets (mimicking 2x2 block of RGB pixels)
    offsets_dst[0] = (0)*dst_stride + (0)*3 + 0; offsets_dst[1] = (0)*dst_stride + (1)*3 + 0;
    offsets_dst[2] = (1)*dst_stride + (1)*3 + 0; offsets_dst[3] = (1)*dst_stride + (0)*3 + 0;
    offsets_dst[4] = (0)*dst_stride + (1)*3 + 1; offsets_dst[5] = (0)*dst_stride + (0)*3 + 1;
    offsets_dst[6] = (1)*dst_stride + (1)*3 + 1; offsets_dst[7] = (1)*dst_stride + (0)*3 + 1;
    offsets_dst[8] = (1)*dst_stride + (1)*3 + 2; offsets_dst[9] = (0)*dst_stride + (0)*3 + 2;
    offsets_dst[10] = (0)*dst_stride + (1)*3 + 2; offsets_dst[11] = (1)*dst_stride + (0)*3 + 2;

    // Precompute source offsets
    offsets_src[0] = (0)*src_stride + 1; // s_01
    offsets_src[1] = (1)*src_stride + 0; // s_10
    offsets_src[2] = (1)*src_stride + 1; // s_11
    offsets_src[3] = (0)*src_stride + 0; // s_00

    for (i = 0; i < width; i += 2) {
        uint8_t val_01 = src[offsets_src[0]];
        uint8_t val_10 = src[offsets_src[1]];
        uint8_t val_11 = src[offsets_src[2]];
        uint8_t val_00 = src[offsets_src[3]];

        dst[offsets_dst[0]] = val_11;
        dst[offsets_dst[1]] = val_11;
        dst[offsets_dst[2]] = val_11;
        dst[offsets_dst[3]] = val_11;

        dst[offsets_dst[4]] = val_01;
        dst[offsets_dst[5]] = ((unsigned int)val_01 + (unsigned int)val_10) >> 1;
        dst[offsets_dst[6]] = ((unsigned int)val_01 + (unsigned int)val_10) >> 1;
        dst[offsets_dst[7]] = val_10;

        dst[offsets_dst[8]] = val_00;
        dst[offsets_dst[9]] = val_00;
        dst[offsets_dst[10]] = val_00;
        dst[offsets_dst[11]] = val_00;

        src += 2;
        dst += 6;
    }
}
