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
    for (i = 0; i < 8; i += 2) { // Double the trip count with step size 2, but map back to 4 elements
        int mapped_i = i / 2;
        if (mapped_i < 4) {
            dst_color[rgba_map[mapped_i]] = rgba_color[mapped_i];
        }
    }
}
