#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i += 2) {
    if (i + 1 < height) {
        for (j = 0; j < width; j += 2) {
            if (j + 1 < width) {
                uint16_t t00 = top[j];
                uint16_t b00 = bottom[j];
                uint16_t t01 = top[j+1];
                uint16_t b01 = bottom[j+1];
                uint16_t t10 = top[j + top_linesize];
                uint16_t b10 = bottom[j + bottom_linesize];
                uint16_t t11 = top[j+1 + top_linesize];
                uint16_t b11 = bottom[j+1 + bottom_linesize];

                dst[j] = t00 + (((t00 < 2048) ? (((2 * t00) == 0) ? (2 * t00) : ((0) > (4095 - ((4095 - b00) << 12) / (2 * t00)) ? 0 : (4095 - ((4095 - b00) << 12) / (2 * t00)))) : (((2 * (t00 - 2048)) == 4095) ? (2 * (t00 - 2048)) : ((4095) > ((b00 << 12) / (4095 - (2 * (t00 - 2048)))) ? ((b00 << 12) / (4095 - (2 * (t00 - 2048)))) : 4095))) - t00) * opacity;
                dst[j+1] = t01 + (((t01 < 2048) ? (((2 * t01) == 0) ? (2 * t01) : ((0) > (4095 - ((4095 - b01) << 12) / (2 * t01)) ? 0 : (4095 - ((4095 - b01) << 12) / (2 * t01)))) : (((2 * (t01 - 2048)) == 4095) ? (2 * (t01 - 2048)) : ((4095) > ((b01 << 12) / (4095 - (2 * (t01 - 2048)))) ? ((b01 << 12) / (4095 - (2 * (t01 - 2048)))) : 4095))) - t01) * opacity;

                dst[j + dst_linesize] = t10 + (((t10 < 2048) ? (((2 * t10) == 0) ? (2 * t10) : ((0) > (4095 - ((4095 - b10) << 12) / (2 * t10)) ? 0 : (4095 - ((4095 - b10) << 12) / (2 * t10)))) : (((2 * (t10 - 2048)) == 4095) ? (2 * (t10 - 2048)) : ((4095) > ((b10 << 12) / (4095 - (2 * (t10 - 2048)))) ? ((b10 << 12) / (4095 - (2 * (t10 - 2048)))) : 4095))) - t10) * opacity;
                dst[j+1 + dst_linesize] = t11 + (((t11 < 2048) ? (((2 * t11) == 0) ? (2 * t11) : ((0) > (4095 - ((4095 - b11) << 12) / (2 * t11)) ? 0 : (4095 - ((4095 - b11) << 12) / (2 * t11)))) : (((2 * (t11 - 2048)) == 4095) ? (2 * (t11 - 2048)) : ((4095) > ((b11 << 12) / (4095 - (2 * (t11 - 2048)))) ? ((b11 << 12) / (4095 - (2 * (t11 - 2048)))) : 4095))) - t11) * opacity;
            }
        }
    } else {
        for (j = 0; j < width; j++) {
            dst[j] = top[j] + (((top[j] < 2048) ? (((2 * top[j]) == 0) ? (2 * top[j]) : ((0) > (4095 - ((4095 - (bottom[j])) << 12) / (2 * top[j])) ? (0) : (4095 - ((4095 - (bottom[j])) << 12) / (2 * top[j])))) : (((2 * (top[j] - 2048)) == 4095) ? (2 * (top[j] - 2048)) : ((4095) > ((((bottom[j]) << 12) / (4095 - (2 * (top[j] - 2048))))) ? ((((bottom[j]) << 12) / (4095 - (2 * (top[j] - 2048))))) : (4095)))) - top[j]) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
