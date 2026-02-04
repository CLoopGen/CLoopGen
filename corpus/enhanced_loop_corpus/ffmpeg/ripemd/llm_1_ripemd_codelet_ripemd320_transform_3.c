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
    n = 0;
    for (int i = 0; i < 16; i += 8) {
        for (int j = 0; j < 8 && n < 16; j++) {
            block[n] = (((const union unaligned_32 *)(buffer + 4 * n))->l);
            n++;
        }
    }
}
