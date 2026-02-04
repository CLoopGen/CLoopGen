#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern ptrdiff_t stride;
extern uint8_t *dst;
extern uint32_t p4a;
extern uint32_t p4b;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with alternating pattern using offset array
    const ptrdiff_t offsets[] = {0, 4, 0, 4, 0, 4, 0, 4}; // Emphasize strided reuse
    uint8_t *d = dst;
    for (int i = 0; i < 8; i++) {
        av_alias32 *target = (av_alias32 *)(d + offsets[i]);
        if (i % 2 == 0) {
            target->u32 = p4a;
        } else {
            target->u32 = p4b;
        }
        d += stride;
    }
}
