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
    int idx = ((y + 1) * angle) >> 5;
    int fact = ((y + 1) * angle) & 31;
    if (!fact) {
        for (x = 0; x < size; x += 4)
            ((((union unaligned_64 *)(&src[(x) + stride * (y)]))->l) = ((((const union unaligned_64 *)(&ref[x + idx + 1]))->l)));
    } else {
        for (x = 0; x < size; x += 4) {
            uint16_t v1 = ref[x + idx + 1];
            uint16_t v2 = ref[x + idx + 2];
            uint16_t v3 = ref[x + 1 + idx + 1];
            uint16_t v4 = ref[x + 1 + idx + 2];
            uint16_t v5 = ref[x + 2 + idx + 1];
            uint16_t v6 = ref[x + 2 + idx + 2];
            uint16_t v7 = ref[x + 3 + idx + 1];
            uint16_t v8 = ref[x + 3 + idx + 2];
            src[(x) + stride * (y)] = ((32 - fact) * v1 + fact * v2 + 16) >> 5;
            src[(x + 1) + stride * (y)] = ((32 - fact) * v3 + fact * v4 + 16) >> 5;
            src[(x + 2) + stride * (y)] = ((32 - fact) * v5 + fact * v6 + 16) >> 5;
            src[(x + 3) + stride * (y)] = ((32 - fact) * v7 + fact * v8 + 16) >> 5;
        }
    }
}
}
