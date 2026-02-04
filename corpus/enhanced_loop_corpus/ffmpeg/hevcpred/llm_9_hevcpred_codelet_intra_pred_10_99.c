#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *left;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp1 = pix;
    uint64_t temp2 = pix ^ 0x123456789ABCDEF0ULL;
    for (i = 0; i < size; i += 8) {
        ((union unaligned_64 *)(left + i))->l = temp1;
        ((union unaligned_64 *)(left + i + 4))->l = temp2;
        temp1 ^= temp2;
        temp2 ^= temp1;
    }
}
