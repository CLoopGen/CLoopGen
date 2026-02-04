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
for (i = 0; i < 4; ++i) {
    if (rgba_map[i] < 4) {
        dst_color[rgba_map[i]] = rgba_color[i];
    }
}
}
