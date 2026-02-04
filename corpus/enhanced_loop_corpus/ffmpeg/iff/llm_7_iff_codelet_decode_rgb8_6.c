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
    for (i = 0; i < length; i++) {
        int offset = local_y * linesize + local_x * sizeof(uint32_t);
        *(uint32_t *)(dst + offset) = pixel;
        local_x += 1;
        if (local_x >= width) {
            local_y += 1;
            if (local_y >= height)
                return;
            local_x = 0;
        }
    }
    // Write back final state if needed (though not observable here)
    x = local_x;
    y = local_y;
}
