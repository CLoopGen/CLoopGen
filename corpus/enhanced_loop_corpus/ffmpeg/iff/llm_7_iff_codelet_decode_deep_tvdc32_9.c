#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int src_size;
extern int width;
extern int height;
extern int linesize;
extern  int16_t *tvdc;
extern int x;
extern int y;
extern int plane;
extern int8_t pixel;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_i = 0;
for (i = 0; i < src_size * 2; prev_i = i) {
    int sel = i >> 1;
    int nibble = (i & 1) ? (src[sel] & 15) : (src[sel] >> 4);
    int d = tvdc[nibble];
    i++;
    if (d) {
        pixel += d;
        int addr = y * linesize + x * 4 + plane;
        dst[addr] = pixel;
        x++;
    } else {
        if (i >= src_size * 2)
            return;
        int raw_val = (i & 1) ? (src[i >> 1] & 15) : (src[i >> 1] >> 4);
        int count = raw_val + 1;
        i++;
        count = (count > width - x) ? (width - x) : count;
        int base_offset = y * linesize + plane;
        for (j = 0; j < count; j++) {
            dst[base_offset + (x + j) * 4] = pixel;
        }
        x += count;
    }
    if (x >= width) {
        plane++;
        if (plane >= 4) {
            y++;
            if (y >= height)
                return;
            plane = 0;
        }
        x = 0;
        pixel = 0;
        i = (prev_i + 3) & ~1;
    }
}
}
