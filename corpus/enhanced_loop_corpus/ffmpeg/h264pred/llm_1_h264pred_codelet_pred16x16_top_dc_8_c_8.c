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
extern int i;
extern uint8_t *src;
extern uint32_t dcsplat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int level1 = 0; level1 < 2; level1++) {
        for (int level2 = 0; level2 < 2; level2++) {
            for (int level3 = 0; level3 < 4; level3++) {
                int offset = (level1 * 32) + (level2 * 16) + (level3 * 4);
                (((av_alias32 *)(src + offset + 0))->u32 = (dcsplat));
                (((av_alias32 *)(src + offset + 4))->u32 = (dcsplat));
                (((av_alias32 *)(src + offset + 8))->u32 = (dcsplat));
                (((av_alias32 *)(src + offset + 12))->u32 = (dcsplat));
            }
        }
        src += stride;
    }
}
