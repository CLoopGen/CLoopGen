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
extern uint32_t dc2splat;
extern uint32_t dc3splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 4; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (j < 2) {
                (((av_alias32 *)(((uint32_t *)(src + i * stride)) + j))->u32 = (dc2splat));
            } else {
                (((av_alias32 *)(((uint32_t *)(src + (i + j - 2) * stride)) + (j % 2)))->u32 = (j % 2 == 1 ? dc3splat : dc2splat));
            }
        }
    }
}
