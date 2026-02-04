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
    for (i = 4; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            uint8_t* target_row = src + (i + j) * stride;
            (((av_alias32 *)(((uint32_t *)(target_row)) + 0))->u32 = (dc2splat));
            (((av_alias32 *)(((uint32_t *)(target_row)) + 1))->u32 = (dc3splat));
        }
    }
}
