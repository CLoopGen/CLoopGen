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
    const int stride = 2;
    for (i = 0; i < size; i += 4 * stride) {
        int j1 = (i * stride) % size;
        int j2 = ((i + 1) * stride) % size;
        int j3 = ((i + 2) * stride) % size;
        int j4 = ((i + 3) * stride) % size;
        (((union unaligned_64 *)(left + size + j1))->l) = pix;
        (((union unaligned_64 *)(left + size + j2))->l) = pix;
        (((union unaligned_64 *)(left + size + j3))->l) = pix;
        (((union unaligned_64 *)(left + size + j4))->l) = pix;
    }
}
