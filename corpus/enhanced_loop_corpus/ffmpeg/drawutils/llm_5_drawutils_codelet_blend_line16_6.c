#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern uint8_t *dst;
extern int dx;
extern int w;
extern unsigned int asrc;
extern unsigned int tau;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w; x++) {
        uint16_t value = (((const union unaligned_16 *)(dst))->l);
        uint32_t product = value * tau + asrc;
        if (product < 0x10000) continue;
        ((((union unaligned_16 *)(dst))->l) = (product >> 16));
        dst += dx;
    }
}
