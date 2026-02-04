#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern uint16_t *left;
extern int size_max_y;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_cache[2] = {pix, pix ^ 0x8000800080008000ULL};
    for (i = 0; i < (size_max_y); i += 8) {
        if (i + 4 < size_max_y) {
            (((union unaligned_64 *)(left + i))->l) = local_cache[0];
            (((union unaligned_64 *)(left + i + 4))->l) = local_cache[1];
        } else if (i < size_max_y) {
            (((union unaligned_64 *)(left + i))->l) = local_cache[0];
        }
    }
}
