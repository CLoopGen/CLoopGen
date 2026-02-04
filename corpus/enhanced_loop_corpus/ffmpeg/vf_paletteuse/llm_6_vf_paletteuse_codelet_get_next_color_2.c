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
    const uint8_t a = (c >> 24) & 255;
    const uint8_t r = (c >> 16) & 255;
    const uint8_t g = (c >> 8) & 255;
    const uint8_t b = c & 255;
    if (a < trans_thresh) {
        continue;
    }
    if (color_used[i] || (a != 255) || r < box->min[0] || g < box->min[1] || b < box->min[2] || r > box->max[0] || g > box->max[1] || b > box->max[2])
        continue;

    uint8_t new_min_r = ranges.min[0];
    uint8_t new_min_g = ranges.min[1];
    uint8_t new_min_b = ranges.min[2];
    uint8_t new_max_r = ranges.max[0];
    uint8_t new_max_g = ranges.max[1];
    uint8_t new_max_b = ranges.max[2];

    if (r < new_min_r)
        new_min_r = r;
    if (g < new_min_g)
        new_min_g = g;
    if (b < new_min_b)
        new_min_b = b;
    if (r > new_max_r)
        new_max_r = r;
    if (g > new_max_g)
        new_max_g = g;
    if (b > new_max_b)
        new_max_b = b;

    ranges.min[0] = new_min_r;
    ranges.min[1] = new_min_g;
    ranges.min[2] = new_min_b;
    ranges.max[0] = new_max_r;
    ranges.max[1] = new_max_g;
    ranges.max[2] = new_max_b;

    tmp_pal[nb_color].value = c;
    tmp_pal[nb_color].pal_id = i;
    nb_color++;
}
}
