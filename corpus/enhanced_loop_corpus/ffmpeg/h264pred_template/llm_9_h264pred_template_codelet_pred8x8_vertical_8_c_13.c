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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    uint32_t modified_a = a + (i << 3);
    uint32_t modified_b = b ^ (i * 7);
    for (int j = 0; j < 2; j++) {
        ((av_alias32 *)(((uint32_t *)(src + (2*i + j) * stride)) + 0))->u32 = modified_a;
        ((av_alias32 *)(((uint32_t *)(src + (2*i + j) * stride)) + 1))->u32 = modified_b;
    }
}
}
