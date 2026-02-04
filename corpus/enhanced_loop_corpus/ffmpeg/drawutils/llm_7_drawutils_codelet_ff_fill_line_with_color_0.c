#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t dst_color[4];
extern uint8_t rgba_color[4];
extern uint8_t rgba_map[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_dst[4] = {0};
    for (i = 0; i < 4; i++) {
        local_dst[i] = rgba_color[i];
        dst_color[rgba_map[i]] = local_dst[i];
    }
    // Introduces artificial WAW and WAR dependencies via local_dst,
    // while maintaining same final write to dst_color.
}
