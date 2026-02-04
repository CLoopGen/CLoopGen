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
    if (dst_height > 0) {
        uint16_t *temp = dst;
        for (j = 0; j < dst_width; ++j) {
            temp[j] = last_line[j];
        }
        i = 1;
        for (; i < dst_height; i++) {
            uint16_t *prev = temp;
            temp += dst_width;
            for (j = 0; j < dst_width; ++j) {
                temp[j] = prev[j];
            }
        }
    }
}
