#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *palette;
extern int i;
extern uint32_t color_count;
extern uint32_t r;
extern uint32_t g;
extern uint32_t b;
extern int color_index;
extern int color_dec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = color_count * 3;
    for (i = 0; i < limit; i++) {
        int idx = i / 3;
        r = g = b = (color_index - (i % 3)) & 0xFF;
        palette[idx] |= (i == idx * 3 ? 255U << 24 : 0) | 
                        (i % 3 == 0 ? r << 16 : (i % 3 == 1 ? g << 8 : b));
        if (i % 3 == 2) {
            color_index -= color_dec;
            if (color_index < 0)
                color_index = 0;
        }
    }
}
