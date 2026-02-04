#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern  uint8_t buffer[64];
extern uint32_t block[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 4; n++) {
        block[n * 4 + 0] = (((const union unaligned_32 *)(buffer + 4 * (n * 4 + 0)))->l);
        block[n * 4 + 1] = (((const union unaligned_32 *)(buffer + 4 * (n * 4 + 1)))->l);
        block[n * 4 + 2] = (((const union unaligned_32 *)(buffer + 4 * (n * 4 + 2)))->l);
        block[n * 4 + 3] = (((const union unaligned_32 *)(buffer + 4 * (n * 4 + 3)))->l);
    }
}
