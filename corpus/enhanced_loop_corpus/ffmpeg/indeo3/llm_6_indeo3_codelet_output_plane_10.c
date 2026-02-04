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
    uint8_t *src_local = src;
    uint8_t *dst_local = dst;
    for (y = 0; y < dst_height; y++) {
        ptrdiff_t row_offset = 0;
        for (x = 0; x < plane->width >> 2; x++) {
            av_alias32 temp;
            temp.u32 = (((((const av_alias32 *)(src_local + row_offset))->u32) & 2139062143) << 1);
            ((av_alias32 *)(dst_local + row_offset))->u32 = temp.u32;
            row_offset += 4;
        }
        for (; row_offset < plane->width; row_offset++)
            dst_local[row_offset] = src_local[row_offset] << 1;
        src_local += pitch;
        dst_local += dst_pitch;
    }
    src = src_local;
    dst = dst_local;
}
