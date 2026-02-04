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
    // Variant 1: Consecutive memory access pattern using array indexing with pointer arithmetic for tmp_pal
    uint32_t *pal_ptr = palette;
    uint8_t *used_ptr = color_used;
    struct color *tmp_ptr = tmp_pal;
    const uint8_t trans = trans_thresh;
    struct color_rect *b = box;
    struct color_rect *r = &ranges;

    for (i = 0; i < 256; i++) {
        const uint32_t c = *pal_ptr++;
        const uint8_t a = (c >> 24) & 255;
        if (a < trans) {
            used_ptr++;
            continue;
        }
        const uint8_t r_val = (c >> 16) & 255;
        const uint8_t g_val = (c >> 8) & 255;
        const uint8_t b_val = c & 255;

        if (*used_ptr++ || (a != 255) ||
            r_val < b->min[0] || g_val < b->min[1] || b_val < b->min[2] ||
            r_val > b->max[0] || g_val > b->max[1] || b_val > b->max[2]) {
            continue;
        }

        if (r_val < r->min[0]) r->min[0] = r_val;
        if (g_val < r->min[1]) r->min[1] = g_val;
        if (b_val < r->min[2]) r->min[2] = b_val;
        if (r_val > r->max[0]) r->max[0] = r_val;
        if (g_val > r->max[1]) r->max[1] = g_val;
        if (b_val > r->max[2]) r->max[2] = b_val;

        tmp_ptr->value = c;
        tmp_ptr->pal_id = i;
        tmp_ptr++;
        nb_color++;
    }
}
