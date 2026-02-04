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
    for (i = 0; i < size; i += 4) {
        if (i % 8 == 0 || pix > 1000) {
            (((union unaligned_64 *)(left + i))->l) = pix;
        } else {
            (((union unaligned_64 *)(left + i))->l) = pix ^ 0xFFFFFFFFFFFFFFFFULL;
        }
    }
}
