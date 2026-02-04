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
    // Variant 2: Strided memory access pattern
    // Access every fourth byte in a strided manner during the first phase,
    // simulating a more scattered access useful for certain SIMD or cache optimization scenarios.
    for (y = 0; y < dst_height; y++) {
        uint8_t *src_row = src;
        uint8_t *dst_row = dst;
        int width_quarter = plane->width >> 2;
        // Stride by 4 bytes using index stepping (byte-level striding)
        for (x = 0; x < width_quarter; x++) {
            size_t offset = x * 4;
            ((av_alias32*)(dst_row + offset))->u32 = (((((const av_alias32*)(src_row + offset))->u32) & 2139062143) << 1);
        }
        // Handle any remaining pixels byte-wise as before
        for (x = width_quarter << 2; x < plane->width; x++)
            dst_row[x] = src_row[x] << 1;
        src += pitch;
        dst += dst_pitch;
    }
}
