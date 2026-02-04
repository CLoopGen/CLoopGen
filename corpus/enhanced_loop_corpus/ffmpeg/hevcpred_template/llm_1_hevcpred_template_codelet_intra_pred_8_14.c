#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *left;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i += 8) {
        (((union unaligned_32 *)(left + size + i))->l) = pix;
        if (i + 4 < size)
            (((union unaligned_32 *)(left + size + i + 4))->l) = pix;
    }
}
