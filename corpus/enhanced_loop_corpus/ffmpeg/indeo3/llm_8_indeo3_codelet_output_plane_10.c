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
    for (y = 0; y < dst_height; y++) {
        for (x = 0; x < plane->width >> 3; x++) {
            av_alias32 *d = (av_alias32 *)(dst);
            const av_alias32 *s = (const av_alias32 *)(src);
            d[0].u32 = (s[0].u32 & 2139062143) << 1;
            d[1].u32 = (s[1].u32 & 2139062143) << 1;
            src += 8;
            dst += 8;
        }
        for (x <<= 3; x < plane->width; x++)
            *dst++ = *src++ << 1;
        src += pitch - plane->width;
        dst += dst_pitch - plane->width;
    }
}
