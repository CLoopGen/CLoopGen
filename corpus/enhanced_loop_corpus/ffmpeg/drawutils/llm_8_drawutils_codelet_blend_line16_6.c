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
for (x = 0; x < w; x += 2) {
    uint16_t value1 = (((const union unaligned_16 *)(dst))->l);
    uint16_t value2 = (((const union unaligned_16 *)(dst + dx))->l);
    ((((union unaligned_16 *)(dst))->l) = ((value1 * tau + asrc) >> 16));
    ((((union unaligned_16 *)(dst + dx))->l) = ((value2 * tau + asrc) >> 16));
    dst += 2 * dx;
}
}
