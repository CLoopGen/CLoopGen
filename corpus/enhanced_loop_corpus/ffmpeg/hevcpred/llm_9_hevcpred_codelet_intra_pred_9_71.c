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
    uint64_t temp2 = pix ^ (pix >> 32);
    for (i = 0; i < size; i += 8) {
        ((union unaligned_64 *)(top + size + i))->l = temp1 + i;
        ((union unaligned_64 *)(top + size + i + 4))->l = temp2 ^ i;
    }
}
