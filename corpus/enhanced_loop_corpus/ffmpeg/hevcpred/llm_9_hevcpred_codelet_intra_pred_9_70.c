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
    uint64_t temp_pix1 = pix;
    uint64_t temp_pix2 = pix ^ 0xAAAAAAAAAAAAAAAALL;
    for (i = 0; i < size; i += 4) {
        ((union unaligned_64 *)(top + i))->l = (i % 8 == 0) ? temp_pix1 : temp_pix2;
    }
}
