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
        for (j = 0; j < dst_width; ++j) {
            dst[j] = (i > 0) ? last_line[j] : 0;
        }
        dst += dst_width;
    }
}
