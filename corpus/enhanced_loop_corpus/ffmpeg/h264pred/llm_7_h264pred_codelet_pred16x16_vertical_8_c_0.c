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
    for (i = 0; i < 16; i++) {
        uint32_t local_a = a ^ i; // Remove loop-carried dependency by making value dependent on loop index
        uint32_t local_b = b ^ (i << 1);
        uint32_t local_c = c ^ (i >> 1);
        uint32_t local_d = d ^ ~i;

        // Reorder stores to break original memory write ordering (eliminate artificial WAW/WAR hazards)
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 3))->u32 = local_d);
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = local_b);
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = local_a);
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 2))->u32 = local_c);
    }
}
