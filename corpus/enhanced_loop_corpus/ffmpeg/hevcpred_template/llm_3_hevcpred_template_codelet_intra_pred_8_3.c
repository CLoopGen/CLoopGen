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
extern int bottom_left_size;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (size - bottom_left_size); i += 8) {
    int offset1 = i;
    int offset2 = i + 4;
    if (offset1 < (size - bottom_left_size))
        (((union unaligned_32 *)(left + size + bottom_left_size + offset1))->l) = pix;
    if (offset2 < (size - bottom_left_size))
        (((union unaligned_32 *)(left + size + bottom_left_size + offset2))->l) = pix;
}
}
