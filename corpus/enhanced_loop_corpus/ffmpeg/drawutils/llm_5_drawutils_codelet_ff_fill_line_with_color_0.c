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
for (i = 0; i < 4; i++) {
    dst_color[rgba_map[i]] = (i % 2 == 0) ? rgba_color[i] : 0;
}
}
