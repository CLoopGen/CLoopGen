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
    for (n = 0; n < 16; n += 2) {
        block[n] = (((const union unaligned_32 *)(buffer + 4 * n))->l);
        if (n + 1 < 16) {
            block[n + 1] = (((const union unaligned_32 *)(buffer + 4 * (n + 1)))->l);
        }
    }
}
