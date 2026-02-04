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
uint8_t temp_buffer[4][3];
for (i = 0; i < width; i += 2) {
    uint16_t s00 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 0])))->l;
    uint16_t s01 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2])))->l;
    uint16_t s10 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 0])))->l;
    uint16_t s11 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2])))->l;

    temp_buffer[0][0] = temp_buffer[1][0] = temp_buffer[2][0] = temp_buffer[3][0] = s11 >> 8;
    temp_buffer[0][1] = temp_buffer[2][1] = s01 >> 8;
    temp_buffer[1][1] = temp_buffer[3][1] = s10 >> 8;
    temp_buffer[0][2] = temp_buffer[1][2] = temp_buffer[2][2] = temp_buffer[3][2] = s00 >> 8;

    unsigned int mixed = (s01 + s10) >> (1 + 8);
    temp_buffer[0][1] = temp_buffer[3][1] = mixed;

    for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 3; ++k) {
            dst[j * dst_stride + k] = temp_buffer[j][k];
        }
    }

    src += 4;
    dst += 6;
}
}
