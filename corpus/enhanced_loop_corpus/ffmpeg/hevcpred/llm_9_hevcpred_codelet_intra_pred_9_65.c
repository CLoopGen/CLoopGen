#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *top;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp1 = pix;
    uint64_t temp2 = pix ^ 0xAAAAAAAAAAAAAAAALL;
    uint64_t temp3 = pix ^ 0x5555555555555555LL;
    uint64_t temp4 = pix ^ 0xF0F0F0F0F0F0F0F0LL;

    for (i = 0; i < size; i += 16) {
        if (i + 12 < size) {
            ((union unaligned_64 *)(top + i + 0))->l = temp1;
            ((union unaligned_64 *)(top + i + 4))->l = temp2;
            ((union unaligned_64 *)(top + i + 8))->l = temp3;
            ((union unaligned_64 *)(top + i + 12))->l = temp4;
        }
    }
}
