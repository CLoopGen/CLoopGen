#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern uint8_t *top;
extern int top_right_size;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (32 - top_right_size); i += 8)
        for (int j = 0; j < 2 && (i + 4 * j) < (32 - top_right_size); ++j)
            ((((union unaligned_32 *)(top + 32 + top_right_size + i + 4 * j))->l) = (pix));
}
