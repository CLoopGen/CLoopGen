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
    for (; i < dst_height; i++) {
        j = 0;
        for (; j < dst_width; j++) {
            if (j % 2 == 0) {
                dst[j] = last_line[j];
            } else {
                dst[j] = last_line[j] + 1;
            }
        }
        dst += dst_width;
    }
}
