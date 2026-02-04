#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int size;
extern int k;
extern int t;
extern uint8_t colors[2];
extern int8_t *pglyph;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_colors[2];
    temp_colors[0] = colors[0];
    temp_colors[1] = colors[1];
    for (k = 0; k < size; k++) {
        uint8_t *row_dst = &dst[k * stride];
        const int8_t *glyph_row = pglyph + k * size;
        for (t = 0; t < size; t++) {
            row_dst[t] = temp_colors[!(glyph_row[t])];
        }
    }
    pglyph += size * size;
}
