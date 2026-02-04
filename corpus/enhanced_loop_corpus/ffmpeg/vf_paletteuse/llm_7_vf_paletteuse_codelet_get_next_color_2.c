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
uint8_t local_min[3] = {ranges.min[0], ranges.min[1], ranges.min[2]};
uint8_t local_max[3] = {ranges.max[0], ranges.max[1], ranges.max[2]};
unsigned int local_count = nb_color;

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

    if (r < local_min[0]) local_min[0] = r;
    if (g < local_min[1]) local_min[1] = g;
    if (b < local_min[2]) local_min[2] = b;
    if (r > local_max[0]) local_max[0] = r;
    if (g > local_max[1]) local_max[1] = g;
    if (b > local_max[2]) local_max[2] = b;

    tmp_pal[local_count].value = c;
    tmp_pal[local_count].pal_id = i;
    local_count++;
}

ranges.min[0] = local_min[0];
ranges.min[1] = local_min[1];
ranges.min[2] = local_min[2];
ranges.max[0] = local_max[0];
ranges.max[1] = local_max[1];
ranges.max[2] = local_max[2];
nb_color = local_count;
}
