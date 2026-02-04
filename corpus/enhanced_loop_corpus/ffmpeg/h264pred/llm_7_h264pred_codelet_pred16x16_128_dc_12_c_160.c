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
    uint64_t val_sequence[4];
    uint64_t base = ((1 << (12 - 1)) + 0) * 281479271743489ULL;
    val_sequence[0] = base;
    val_sequence[1] = base ^ 0x1111111111111111ULL;
    val_sequence[2] = base ^ 0x2222222222222222ULL;
    val_sequence[3] = base ^ 0x3333333333333333ULL;

    for (i = 0; i < 16; i++) {
        ((av_alias64 *)(src + 0))->u64 = val_sequence[(i + 0) & 3];
        ((av_alias64 *)(src + 4))->u64 = val_sequence[(i + 1) & 3];
        ((av_alias64 *)(src + 8))->u64 = val_sequence[(i + 2) & 3];
        ((av_alias64 *)(src + 12))->u64 = val_sequence[(i + 3) & 3];
        src += stride;
    }
}
