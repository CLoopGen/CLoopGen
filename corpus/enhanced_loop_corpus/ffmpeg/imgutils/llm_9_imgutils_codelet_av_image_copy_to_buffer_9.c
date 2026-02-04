#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern  uint8_t * src_data[4];
extern int i;
extern uint32_t *d32;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        uint32_t val1 = ((const union unaligned_32 *)(src_data[1] + 4 * i))->l;
        uint32_t val2 = ((const union unaligned_32 *)(src_data[1] + 4 * (i + 1)))->l;
        uint32_t val3 = ((const union unaligned_32 *)(src_data[1] + 4 * (i + 2)))->l;
        uint32_t val4 = ((const union unaligned_32 *)(src_data[1] + 4 * (i + 3)))->l;
        ((union unaligned_32 *)(d32 + i))->l = val1 ^ val2 ^ val3 ^ val4;
    }
}
