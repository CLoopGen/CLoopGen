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
    for (n = 0; n < 32; n++) {
        int idx = n / 2;
        block[idx] = (((const union unaligned_32 *)(buffer + 4 * idx))->l);
        block[idx] ^= (uint32_t)(n * n); // Add computational intensity with arithmetic
    }
}
