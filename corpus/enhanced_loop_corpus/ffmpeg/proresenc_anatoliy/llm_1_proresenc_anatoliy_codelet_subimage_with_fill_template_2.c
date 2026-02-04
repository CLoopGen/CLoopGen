#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern unsigned int dst_width;
extern unsigned int dst_height;
extern int i;
extern int j;
extern uint16_t *last_line;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dst_height; i++) {
        j = 0;
        for (; j < dst_width; ++j) {
            dst[i * dst_width + j] = last_line[j];
        }
    }
}
