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
    int stride = 8;
    for (i = 0; i < size; i += stride)
        if (i + 3 < size)
            ((((union unaligned_32 *)(top + i))->l) = (pix));
}
