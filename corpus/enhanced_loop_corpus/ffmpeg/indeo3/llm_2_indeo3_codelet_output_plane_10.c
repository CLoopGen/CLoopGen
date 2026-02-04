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
    // Variant 1: Consecutive memory access with unrolled accumulation
    // Instead of processing one 32-bit chunk at a time, we process two consecutively to improve spatial locality.
    for (y = 0; y < dst_height; y++) {
        uint8_t *src_row = src;
        uint8_t *dst_row = dst;
        for (x = 0; x < plane->width >> 3; x++) {
            av_alias32 *d = (av_alias32*)(dst_row + (x << 3));
            const av_alias32 *s = (const av_alias32*)(src_row + (x << 3));
            d[0].u32 = (s[0].u32 & 2139062143) << 1;
            d[1].u32 = (s[1].u32 & 2139062143) << 1;
        }
        for (x <<= 3; x < plane->width; x++)
            dst_row[x] = src_row[x] << 1;
        src += pitch;
        dst += dst_pitch;
    }
}
