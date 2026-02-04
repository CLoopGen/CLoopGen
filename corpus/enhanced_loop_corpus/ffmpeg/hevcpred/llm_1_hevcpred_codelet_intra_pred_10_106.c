#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *left;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; ++i)
        for (int stride = 0; stride < 2; ++stride)
            if (((i * 2) + stride) % 2 == 0) {
                int idx = (i * 2) + stride;
                ((((union unaligned_64 *)(left + idx))->l) = (pix));
            }
}
