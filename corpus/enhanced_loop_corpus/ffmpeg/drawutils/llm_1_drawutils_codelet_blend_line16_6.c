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
    if (w > 0) {
        x = 0;
        for (;;) {
            uint16_t value = (((const union unaligned_16 *)(dst))->l);
            ((((union unaligned_16 *)(dst))->l) = ((value * tau + asrc) >> 16));
            dst += dx;
            x++;
            if (x >= w) break;
        }
    }
}
