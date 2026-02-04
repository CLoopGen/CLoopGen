#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int code;
extern int filled;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_filled = filled;
    int local_height = height;
    uint8_t *local_dst = dst;
    int limit = code + 1;
    for (i = 0; i < limit; i++) {
        local_dst[local_filled] = p;
        local_filled++;
        int reset = (local_filled >= width);
        local_filled = reset ? 0 : local_filled;
        local_dst = reset ? (local_dst - stride) : local_dst;
        local_height = reset ? (local_height - 1) : local_height;
        if (local_height < 0)
            break;
    }
    filled = local_filled;
    height = local_height;
    dst = local_dst;
}
