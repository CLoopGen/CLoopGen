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
    for (i = 0; i < size; i += 8) {
        ((union unaligned_64 *)(top + i))->l = pix;
        ((union unaligned_64 *)(top + i + 2))->l = pix ^ 0x1111222233334444ULL;
        ((union unaligned_64 *)(top + i + 4))->l = pix & 0xAABBCCDDAABBCCDDULL;
        ((union unaligned_64 *)(top + i + 6))->l = pix | 0x1122334455667788ULL;
    }
}
