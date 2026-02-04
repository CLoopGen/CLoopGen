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
            int idx = (j < 2) ? 0 : 1;
            uint32_t value = (j % 2 == 0) ? dc2splat : dc3splat;
            (((av_alias32 *)(((uint32_t *)(src + i * stride)) + idx))->u32 = value);
        }
    }
}
