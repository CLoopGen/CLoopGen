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
extern uint16_t *dst;
extern uint64_t p4a;
extern uint64_t p4b;
extern uint64_t p4c;
extern uint64_t p4d;
extern uint64_t p4e;
extern uint64_t p4f;
extern uint64_t p4g;
extern uint64_t p4h;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 32; y++) {
        uint64_t local_p4a = p4a + y;
        uint64_t local_p4b = p4b + y;
        uint64_t local_p4c = p4c + y;
        uint64_t local_p4d = p4d + y;
        uint64_t local_p4e = p4e + y;
        uint64_t local_p4f = p4f + y;
        uint64_t local_p4g = p4g + y;
        uint64_t local_p4h = p4h + y;

        (((av_alias64 *)(dst + 0))->u64 = (local_p4a));
        (((av_alias64 *)(dst + 4))->u64 = (local_p4b));
        (((av_alias64 *)(dst + 8))->u64 = (local_p4c));
        (((av_alias64 *)(dst + 12))->u64 = (local_p4d));
        (((av_alias64 *)(dst + 16))->u64 = (local_p4e));
        (((av_alias64 *)(dst + 20))->u64 = (local_p4f));
        (((av_alias64 *)(dst + 24))->u64 = (local_p4g));
        (((av_alias64 *)(dst + 28))->u64 = (local_p4h));

        dst += stride;
    }
}
