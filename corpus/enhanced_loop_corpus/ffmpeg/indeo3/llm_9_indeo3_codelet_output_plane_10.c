#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Plane {
    uint8_t *buffers[2];
    uint8_t *pixels[2];
    uint32_t width;
    uint32_t height;
    ptrdiff_t pitch;
} Plane;

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern  Plane *plane;
extern uint8_t *dst;
extern ptrdiff_t dst_pitch;
extern int dst_height;
extern int x;
extern int y;
extern  uint8_t *src;
extern ptrdiff_t pitch;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < dst_height; y += 2) {
        ptrdiff_t local_src_offset = 0;
        ptrdiff_t local_dst_offset = 0;
        for (x = 0; x < plane->width >> 2; x++) {
            ((av_alias32 *)(dst + local_dst_offset))->u32 = (((((const av_alias32 *)(src + local_src_offset))->u32) & 2139062143) << 1);
            local_src_offset += 4;
            local_dst_offset += 4;
        }
        for (; local_src_offset < plane->width; local_src_offset++, local_dst_offset++)
            dst[local_dst_offset] = src[local_src_offset] << 1;
        src += pitch;
        dst += dst_pitch;
        if (y + 1 < dst_height) {
            src += pitch;
            dst += dst_pitch;
        }
    }
}
