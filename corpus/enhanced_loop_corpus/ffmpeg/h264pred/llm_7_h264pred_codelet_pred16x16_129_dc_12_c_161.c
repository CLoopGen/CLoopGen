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
    uint64_t val0, val1, val2, val3;
    val0 = (((1 << (12 - 1)) + 1) * 281479271743489ULL);
    val1 = val0 ^ 0x1234567812345678ULL;
    val2 = val1 ^ 0x1234567812345678ULL;
    val3 = val2 ^ 0x1234567812345678ULL;
    for (i = 0; i < 16; i++) {
        (((av_alias64 *)(src + 0))->u64 = val0);
        (((av_alias64 *)(src + 4))->u64 = val1);
        (((av_alias64 *)(src + 8))->u64 = val2);
        (((av_alias64 *)(src + 12))->u64 = val3);
        val0 = val3 ^ 0x8765432187654321ULL;
        val1 = val0 ^ 0x1234567812345678ULL;
        val2 = val1 ^ 0x1234567812345678ULL;
        val3 = val2 ^ 0x1234567812345678ULL;
        src += stride;
    }
}
