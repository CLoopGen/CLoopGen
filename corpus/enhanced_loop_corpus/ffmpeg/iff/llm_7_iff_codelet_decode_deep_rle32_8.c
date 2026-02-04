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
extern int size;
extern uint32_t pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_x = x;
    int local_y = y;
    int remaining = size;
    while (remaining > 0) {
        if (local_x >= width) {
            local_x = 0;
            local_y += 1;
            if (local_y >= height)
                break;
        }
        int offset = local_y * linesize + local_x * 4;
        *(uint32_t *)(dst + offset) = pixel;
        local_x += 1;
        remaining -= 1;
    }
    x = local_x;
    y = local_y;
}
