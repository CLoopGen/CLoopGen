#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i += 2) {
    // Use strided access by precomputing column offsets and stepping through components separately
    int col = i / 2; // Assuming two pixels processed per iteration

    // Strided access: treat src as packed pairs of 16-bit values in row-major order
    const uint8_t *s0 = &src[src_stride * 0];
    const uint8_t *s1 = &src[src_stride * 1];

    uint16_t s00 = ((const union unaligned_16 *)&s0[2 * 0])->l;
    uint16_t s02 = ((const union unaligned_16 *)&s0[2 * 1])->l;
    uint16_t s10 = ((const union unaligned_16 *)&s1[2 * 0])->l;
    uint16_t s12 = ((const union unaligned_16 *)&s1[2 * 1])->l;

    // Write to dst with stride-3 layout explicitly calculated per channel
    uint8_t *dptr = &dst[0];
    dptr[col * 6 + 0] = dptr[col * 6 + 3] = dptr[col * 6 + 7] = dptr[col * 6 + 4] = s12 >> 8;
    dptr[col * 6 + 4] = s02 >> 8;
    dptr[col * 6 + 1] = dptr[col * 6 + 7] = ((unsigned int)s02 + (unsigned int)s10) >> 9;
    dptr[col * 6 + 4] = s10 >> 8;
    dptr[col * 6 + 5] = dptr[col * 6 + 2] = dptr[col * 6 + 5] = dptr[col * 6 + 2] = s00 >> 8;

    src += 4;
    dst += 6;
}
}
