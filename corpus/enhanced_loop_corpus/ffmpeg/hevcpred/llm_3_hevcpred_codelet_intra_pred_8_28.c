#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *top;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int stride = 16;
    for (i = 0; i < size; i += 4) {
        int index = (i * stride) % size;
        (((union unaligned_32 *)(top + index))->l) = pix;
    }
}
