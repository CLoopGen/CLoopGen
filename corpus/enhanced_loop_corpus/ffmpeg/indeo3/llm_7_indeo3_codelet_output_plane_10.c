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
        uint8_t *src_row = src + y * pitch;
        uint8_t *dst_row = dst + y * dst_pitch;
        int vectorized_width = (plane->width >> 2) << 2;
        int i;

        for (i = 0; i < vectorized_width; i += 4) {
            uint32_t val = ((const uint32_t*)(src_row + i))[0];
            uint32_t masked = (val & 2139062143) << 1;
            ((uint32_t*)(dst_row + i))[0] = masked;
        }

        for (; i < plane->width; i++) {
            dst_row[i] = src_row[i] << 1;
        }
    }
}
