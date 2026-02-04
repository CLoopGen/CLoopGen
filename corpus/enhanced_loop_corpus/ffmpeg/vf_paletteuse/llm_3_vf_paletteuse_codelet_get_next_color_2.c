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
    // Variant 2: Strided memory access by processing palette in reverse order with stride of 4 (unrolled-like pattern)
    // This changes access pattern to non-sequential, simulating strided access for better cache behavior exploration
    nb_color = 0; // Ensure counter is reset appropriately
    const uint8_t trans = trans_thresh;
    struct color_rect *b = box;
    struct color_rect *r = &ranges;

    // Process indices in reverse with unrolled steps (stride simulation)
    for (i = 255; i >= 0; i--) {
        const uint32_t c = palette[i];
        const uint8_t a = (c >> 24) & 255;
        if (a < trans) continue;

        const uint8_t comp[4] = {
            (c >> 16) & 255,  // r
            (c >> 8) & 255,   // g
            c & 255,          // b
            a
        };

        // Use local array for component access to simulate structured but indirect use
        if (color_used[i] || (comp[3] != 255) ||
            comp[0] < b->min[0] || comp[1] < b->min[1] || comp[2] < b->min[2] ||
            comp[0] > b->max[0] || comp[1] > b->max[1] || comp[2] > b->max[2]) {
            continue;
        }

        // Update ranges using the same component array
        if (comp[0] < r->min[0]) r->min[0] = comp[0];
        if (comp[1] < r->min[1]) r->min[1] = comp[1];
        if (comp[2] < r->min[2]) r->min[2] = comp[2];
        if (comp[0] > r->max[0]) r->max[0] = comp[0];
        if (comp[1] > r->max[1]) r->max[1] = comp[1];
        if (comp[2] > r->max[2]) r->max[2] = comp[2];

        tmp_pal[nb_color].value = c;
        tmp_pal[nb_color].pal_id = i;
        nb_color++;
    }
}
