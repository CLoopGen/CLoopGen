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
    uint64_t temp1 = pix * 3;
    uint64_t temp2 = pix + 0x123456789ABCDEF0;
    for (i = 0; i < size; i += 2) {
        if (i % 8 < 4) {
            ((union unaligned_64 *)(top + i))->l = temp1;
        } else {
            ((union unaligned_64 *)(top + i))->l = temp2;
        }
    }
}
