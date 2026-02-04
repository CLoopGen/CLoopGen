#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct color_rect {
    uint8_t min[3];
    uint8_t max[3];
};


struct color {
    uint32_t value;
    uint8_t pal_id;
};


extern  uint8_t *color_used;
extern  uint32_t *palette;
extern  int trans_thresh;
extern  struct color_rect *box;
extern int i;
extern unsigned int nb_color;
extern struct color_rect ranges;
extern struct color tmp_pal[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; i++) {
    const uint32_t c = palette[i];
    const uint8_t a = c >> 24 & 255;
    const uint8_t r = c >> 16 & 255;
    const uint8_t g = c >> 8 & 255;
    const uint8_t b = c & 255;

    int skip = 0;
    if (a < trans_thresh) skip = 1;
    if (!skip && (color_used[i] || (a != 255))) skip = 1;
    if (!skip && (r >= box->min[0] && g >= box->min[1] && b >= box->min[2] &&
                  r <= box->max[0] && g <= box->max[1] && b <= box->max[2])) {
        if (r < ranges.min[0]) ranges.min[0] = r;
        if (g < ranges.min[1]) ranges.min[1] = g;
        if (b < ranges.min[2]) ranges.min[2] = b;
        if (r > ranges.max[0]) ranges.max[0] = r;
        if (g > ranges.max[1]) ranges.max[1] = g;
        if (b > ranges.max[2]) ranges.max[2] = b;
        tmp_pal[nb_color].value = c;
        tmp_pal[nb_color].pal_id = i;
        nb_color++;
    }
}
}
