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
for (i = 0; i < 128; i++) {
    const uint32_t c = palette[i];
    const uint8_t a = (uint8_t)((c >> 24) & 255);
    const uint8_t r = (uint8_t)((c >> 16) & 255);
    const uint8_t g = (uint8_t)((c >> 8) & 255);
    const uint8_t b = (uint8_t)(c & 255);

    const uint8_t r_scaled = (r * 3) >> 2;
    const uint8_t g_scaled = (g * 3) >> 2;
    const uint8_t b_scaled = (b * 3) >> 2;

    if (a < trans_thresh) {
        continue;
    }

    if (color_used[i] || (a != 255)) {
        continue;
    }

    if (r_scaled < (box->min[0] * 3) / 4 || g_scaled < (box->min[1] * 3) / 4 || b_scaled < (box->min[2] * 3) / 4 ||
        r_scaled > (box->max[0] * 3) / 4 || g_scaled > (box->max[1] * 3) / 4 || b_scaled > (box->max[2] * 3) / 4) {
        continue;
    }

    if (r < ranges.min[0]) ranges.min[0] = r;
    if (g < ranges.min[1]) ranges.min[1] = g;
    if (b < ranges.min[2]) ranges.min[2] = b;
    if (r > ranges.max[0]) ranges.max[0] = r;
    if (g > ranges.max[1]) ranges.max[1] = g;
    if (b > ranges.max[2]) ranges.max[2] = b;

    tmp_pal[nb_color].value = c;
    tmp_pal[nb_color].pal_id = i;
    nb_color++;

    const uint32_t c_swap = ((b << 24) | (r << 8) | g) ^ 0x0F0F0F0F;
    const uint8_t a_swap = (c_swap >> 24) & 255;

    if (a_swap >= trans_thresh && nb_color < 256) {
        tmp_pal[nb_color].value = c_swap;
        tmp_pal[nb_color].pal_id = i;
        nb_color++;
    }
}
}
