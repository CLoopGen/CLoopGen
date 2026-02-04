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
extern  uint64_t a;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_a = a;
    for (i = 0; i < 16; i += 2) {
        av_alias64 *ptr0 = (av_alias64 *)((uint64_t *)(src + i * stride));
        av_alias64 *ptr1 = (av_alias64 *)((uint64_t *)(src + (i+1) * stride));
        ptr0->u64 = local_a;
        ptr0[1].u64 = local_a;
        ptr1->u64 = local_a;
        ptr1[1].u64 = local_a;
    }
}
