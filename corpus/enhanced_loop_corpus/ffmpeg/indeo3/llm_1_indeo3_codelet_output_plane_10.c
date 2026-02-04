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
    // Variant 2: Increased loop nesting depth - break the first part into byte-wise nested loop over 4-byte chunks
    for (y = 0; y < dst_height; y++) {
        uint32_t block_count = plane->width >> 2;
        uint32_t remainder = plane->width & 3;
        for (x = 0; x < block_count; x++) {
            uint32_t temp = ((((const av_alias32 *)(src))->u32) & 2139062143) << 1;
            // Unroll into byte-level assignments using nested loop
            for (int b = 0; b < 4; b++) {
                dst[b] = ((uint8_t*)&temp)[b];
            }
            src += 4;
            dst += 4;
        }
        // Handle remaining pixels
        for (x = 0; x < remainder; x++) {
            *dst++ = *src++ << 1;
        }
        src += pitch - plane->width;
        dst += dst_pitch - plane->width;
    }
}
