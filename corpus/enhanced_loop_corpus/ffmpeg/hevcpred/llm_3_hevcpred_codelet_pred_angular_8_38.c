#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint8_t *src;
extern int angle;
extern  uint8_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < size; y++) {
    int idx = ((y + 1) * angle) >> 5;
    int fact = ((y + 1) * angle) & 31;
    ptrdiff_t base_src = stride * y;
    const uint8_t* ref_base = &ref[idx + 1];
    if (fact) {
        for (x = 0; x < size; x += 4) {
            src[base_src + x] = ((32 - fact) * ref_base[x] + fact * ref_base[x + 1] + 16) >> 5;
            src[base_src + x + 1] = ((32 - fact) * ref_base[x + 1] + fact * ref_base[x + 2] + 16) >> 5;
            src[base_src + x + 2] = ((32 - fact) * ref_base[x + 2] + fact * ref_base[x + 3] + 16) >> 5;
            src[base_src + x + 3] = ((32 - fact) * ref_base[x + 3] + fact * ref_base[x + 4] + 16) >> 5;
        }
    } else {
        for (x = 0; x < size; x += 4) {
            (((union unaligned_32 *)(&src[base_src + x]))->l) = (((const union unaligned_32 *)(ref_base + x))->l);
        }
    }
}
}
