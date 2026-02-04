#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern int height;
extern int linesize;
extern int x;
extern int y;
extern int i;
extern int length;
extern uint32_t pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_x = x;
    int local_y = y;
    int completed = 0;
    for (i = 0; i < length && !completed; i++) {
        int offset = local_y * linesize + local_x * sizeof(uint16_t);
        uint16_t val = (uint16_t)pixel;
        *(uint16_t *)(dst + offset) = val;
        local_x += 1;
        if (local_x >= width) {
            local_x = 0;
            local_y += 1;
            if (local_y >= height)
                completed = 1;
        }
    }
    x = local_x;
    y = local_y;
}
