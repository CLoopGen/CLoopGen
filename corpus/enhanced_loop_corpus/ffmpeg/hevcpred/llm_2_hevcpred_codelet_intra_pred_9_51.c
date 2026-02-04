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
extern int bottom_left_size;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (size - bottom_left_size); i += 4) {
        ((((union unaligned_64 *)(left + size + bottom_left_size + i))->l) = (pix));
        ((((union unaligned_64 *)(left + size + bottom_left_size + i + 1))->l) = (pix));
        ((((union unaligned_64 *)(left + size + bottom_left_size + i + 2))->l) = (pix));
        ((((union unaligned_64 *)(left + size + bottom_left_size + i + 3))->l) = (pix));
    }
}
