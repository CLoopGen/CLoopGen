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
    int outer_n;
    for (outer_n = 0; outer_n < 4; outer_n++) {
        for (n = 0; n < 4; n++) {
            int index = 4 * outer_n + n;
            block[index] = (((const union unaligned_32 *)(buffer + 4 * index))->l);
        }
    }
}
