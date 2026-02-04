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

extern int i;
extern uint8_t *src;
extern int stride;
extern  uint32_t a;
extern  uint32_t b;
extern  uint32_t c;
extern  uint32_t d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        uint32_t computed_a = a + (i << 3);
        uint32_t computed_b = b + (i * 7);
        uint32_t computed_c = c ^ (i * 13);
        uint32_t computed_d = d ^ ((i + 1) * 17);

        ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = computed_a;
        ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = computed_b;
        ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 2))->u32 = computed_c;
        ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 3))->u32 = computed_d;

        // Duplicate store with modified values to increase computational density
        ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 4))->u32 = computed_a ^ 0xFFFFFFFFU;
        ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 5))->u32 = computed_b ^ 0xFFFFFFFFU;
        ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 6))->u32 = computed_c ^ 0xFFFFFFFFU;
        ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 7))->u32 = computed_d ^ 0xFFFFFFFFU;
    }
}
