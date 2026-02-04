#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

extern ptrdiff_t stride;
extern int i;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int level1 = 0; level1 < 2; level1++) {
        for (int level2 = 0; level2 < 2; level2++) {
            for (int level3 = 0; level3 < 4; level3++) {
                int offset = level2 * 8 + level3 * 4;
                (((av_alias64 *)(src + offset))->u64 = ((((1 << (9 - 1)) - 1) * 281479271743489ULL)));
            }
        }
        src += stride;
    }
}
