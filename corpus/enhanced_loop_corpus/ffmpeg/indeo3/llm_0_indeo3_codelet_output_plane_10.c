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
    // Variant 1: Flattened loop nesting - reduce depth by merging inner loops into a single loop with conditional logic
    for (y = 0; y < dst_height; y++) {
        uint32_t width = plane->width;
        for (x = 0; x < width; x++) {
            if (x < (width >> 2)) {
                (((av_alias32 *)(dst))->u32 = (((((const av_alias32 *)(src))->u32) & 2139062143) << 1));
                src += 4;
                dst += 4;
                x += 3; // account for quad-byte step
            } else {
                *dst++ = *src++ << 1;
            }
        }
        src += pitch - width;
        dst += dst_pitch - width;
    }
}
