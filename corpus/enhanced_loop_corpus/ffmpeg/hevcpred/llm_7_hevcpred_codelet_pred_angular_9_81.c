#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint16_t *src;
extern int angle;
extern  uint16_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < size; y++) {
    int idx_base = (y * angle) >> 5;
    int fact = (y * angle) & 31;
    if (fact && y > 0) {
        int idx = idx_base;
        for (x = 0; x < size; x += 4) {
            uint16_t val1 = ref[x + idx + 1];
            uint16_t val2 = ref[x + idx + 2];
            uint16_t interp = ((32 - fact) * val1 + fact * val2 + 16) >> 5;
            src[(x) + stride * (y)] = interp;
            val1 = ref[x + 1 + idx + 1];
            val2 = ref[x + 1 + idx + 2];
            interp = ((32 - fact) * val1 + fact * val2 + 16) >> 5;
            src[(x + 1) + stride * (y)] = interp;
            val1 = ref[x + 2 + idx + 1];
            val2 = ref[x + 2 + idx + 2];
            interp = ((32 - fact) * val1 + fact * val2 + 16) >> 5;
            src[(x + 2) + stride * (y)] = interp;
            val1 = ref[x + 3 + idx + 1];
            val2 = ref[x + 3 + idx + 2];
            interp = ((32 - fact) * val1 + fact * val2 + 16) >> 5;
            src[(x + 3) + stride * (y)] = interp;
        }
    } else {
        int idx = idx_base + 1;
        for (x = 0; x < size; x += 4) {
            union unaligned_64 temp;
            temp.l = ((const union unaligned_64 *)(&ref[x + idx]))->l;
            ((union unaligned_64 *)(&src[x + stride * y]))->l = temp.l;
        }
    }
}
}
