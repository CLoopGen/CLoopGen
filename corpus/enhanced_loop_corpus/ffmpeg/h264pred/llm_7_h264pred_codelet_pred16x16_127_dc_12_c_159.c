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
    uint16_t *temp_src[16];
    ptrdiff_t local_stride = stride;
    uint64_t val_seq[4];
    val_seq[0] = (((1 << (12 - 1)) - 1) * 281479271743489ULL);
    val_seq[1] = val_seq[0] ^ 0xAAAAAAAAAAAAAAAAULL;
    val_seq[2] = val_seq[0] ^ 0x5555555555555555ULL;
    val_seq[3] = val_seq[0] ^ 0xFFFFFFFFFFFFFFFFULL;

    temp_src[0] = src;
    for (i = 1; i < 16; i++) {
        temp_src[i] = temp_src[i-1] + local_stride;
    }

    for (i = 0; i < 16; i++) {
        int idx = (i * 7) % 4;
        ((av_alias64 *)(temp_src[i] + 0))->u64 = val_seq[idx];
        ((av_alias64 *)(temp_src[i] + 4))->u64 = val_seq[(idx + 1) % 4];
        ((av_alias64 *)(temp_src[i] + 8))->u64 = val_seq[(idx + 2) % 4];
        ((av_alias64 *)(temp_src[i] + 12))->u64 = val_seq[(idx + 3) % 4];
    }
}
