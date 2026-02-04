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
extern uint32_t dc6splat;
extern uint32_t dc7splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 12; i < 14; i++) {
        for (int offset = 0; offset < 2; offset++) {
            int idx = i + offset;
            (((av_alias32 *)(((uint32_t *)(src + idx * stride)) + 0))->u32 = (offset == 0) ? dc6splat : dc7splat);
            (((av_alias32 *)(((uint32_t *)(src + idx * stride)) + 1))->u32 = (offset == 0) ? dc7splat : dc6splat);
        }
    }
}
