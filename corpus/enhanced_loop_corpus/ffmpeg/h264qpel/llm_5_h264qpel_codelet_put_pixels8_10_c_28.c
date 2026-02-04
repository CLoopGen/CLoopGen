#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        uint64_t temp1, temp2;
        const union unaligned_64 *p1 = (const union unaligned_64 *)(pixels);
        const union unaligned_64 *p2 = (const union unaligned_64 *)(pixels + 4 * sizeof(uint16_t));
        
        temp1 = p1->l;
        temp2 = p2->l;

        if (temp1 != 0) {
            *((uint64_t *)block) = temp1;
            if (temp2 != 0) {
                *((uint64_t *)(block + 4 * sizeof(uint16_t))) = temp2;
            }
        }

        pixels += line_size;
        block += line_size;
    }
}
