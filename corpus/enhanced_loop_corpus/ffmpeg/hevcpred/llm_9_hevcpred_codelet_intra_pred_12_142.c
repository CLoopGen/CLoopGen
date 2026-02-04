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
    uint64_t temp_pix = pix ^ 0x1111222233334444ULL;
    for (i = 0; i < size; i += 4) {
        uint64_t combined = (((union unaligned_64 *)(left + i))->l) + temp_pix;
        ((((union unaligned_64 *)(left + i))->l) = (combined));
    }
}
