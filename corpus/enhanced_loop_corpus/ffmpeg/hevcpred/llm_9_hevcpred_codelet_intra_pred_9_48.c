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
extern int top_right_size;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_pix = pix ^ 0xAAAAAAAAAAAAAAAALL;
    for (i = 0; i < (size - top_right_size); i += 2) {
        if (i + 1 < (size - top_right_size)) {
            ((union unaligned_64 *)(top + size + top_right_size + i))->l = pix;
            ((union unaligned_64 *)(top + size + top_right_size + i + 1))->l = temp_pix;
            i += 1;
        } else {
            ((union unaligned_64 *)(top + size + top_right_size + i))->l = pix;
        }
    }
}
