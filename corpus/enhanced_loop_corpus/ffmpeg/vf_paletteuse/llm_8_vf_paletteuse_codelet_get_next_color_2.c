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
for (i = 0; i < 256; i += 2) {
    const uint32_t c1 = palette[i];
    const uint8_t a1 = c1 >> 24 & 255;
    const uint8_t r1 = c1 >> 16 & 255;
    const uint8_t g1 = c1 >> 8 & 255;
    const uint8_t b1 = c1 & 255;

    if (a1 >= trans_thresh && !color_used[i] && a1 == 255 &&
        r1 >= box->min[0] && g1 >= box->min[1] && b1 >= box->min[2] &&
        r1 <= box->max[0] && g1 <= box->max[1] && b1 <= box->max[2]) {
        
        if (r1 < ranges.min[0]) ranges.min[0] = r1;
        if (g1 < ranges.min[1]) ranges.min[1] = g1;
        if (b1 < ranges.min[2]) ranges.min[2] = b1;
        if (r1 > ranges.max[0]) ranges.max[0] = r1;
        if (g1 > ranges.max[1]) ranges.max[1] = g1;
        if (b1 > ranges.max[2]) ranges.max[2] = b1;

        tmp_pal[nb_color].value = c1;
        tmp_pal[nb_color].pal_id = i;
        nb_color++;
    }

    if (i + 1 < 256) {
        const uint32_t c2 = palette[i + 1];
        const uint8_t a2 = c2 >> 24 & 255;
        const uint8_t r2 = c2 >> 16 & 255;
        const uint8_t g2 = c2 >> 8 & 255;
        const uint8_t b2 = c2 & 255;

        if (a2 >= trans_thresh && !color_used[i + 1] && a2 == 255 &&
            r2 >= box->min[0] && g2 >= box->min[1] && b2 >= box->min[2] &&
            r2 <= box->max[0] && g2 <= box->max[1] && b2 <= box->max[2]) {

            if (r2 < ranges.min[0]) ranges.min[0] = r2;
            if (g2 < ranges.min[1]) ranges.min[1] = g2;
            if (b2 < ranges.min[2]) ranges.min[2] = b2;
            if (r2 > ranges.max[0]) ranges.max[0] = r2;
            if (g2 > ranges.max[1]) ranges.max[1] = g2;
            if (b2 > ranges.max[2]) ranges.max[2] = b2;

            tmp_pal[nb_color].value = c2;
            tmp_pal[nb_color].pal_id = i + 1;
            nb_color++;
        }
    }
}
}
