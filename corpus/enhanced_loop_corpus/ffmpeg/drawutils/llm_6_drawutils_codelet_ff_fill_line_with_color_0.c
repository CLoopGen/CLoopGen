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
    uint8_t temp[4];
    for (i = 0; i < 4; i++)
        temp[i] = rgba_color[i];
    for (i = 0; i < 4; i++)
        dst_color[rgba_map[i]] = temp[i];
}
