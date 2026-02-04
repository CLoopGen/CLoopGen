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
    for (k = 0; k < size; k++) {
        int base_index = k * stride;
        for (t = 0; t < size; t++) {
            int idx = t + base_index;
            uint8_t color_idx = !(*pglyph++);
            if (color_idx == 0 && t % 2 == 0)
                dst[idx] = colors[0];
            else
                dst[idx] = colors[1];
        }
    }
}
