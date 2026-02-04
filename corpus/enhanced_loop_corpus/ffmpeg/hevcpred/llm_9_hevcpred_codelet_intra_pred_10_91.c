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
    uint64_t temp_pix = pix ^ 0x8080808080808080ULL;
    for (i = 0; i < (size - top_right_size); i += 4) {
        uint64_t computed = (i % 3) ? pix : temp_pix;
        ((((union unaligned_64 *)(top + size + top_right_size + i))->l) = computed);
    }
}
