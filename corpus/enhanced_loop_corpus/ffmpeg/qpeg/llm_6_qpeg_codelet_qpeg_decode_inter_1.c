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
    int temp_filled = filled;
    int temp_height = height;
    uint8_t *temp_dst = dst;
    for (i = 0; i <= code; i++) {
        temp_dst[temp_filled++] = p;
        if (temp_filled >= width) {
            temp_filled = 0;
            temp_dst -= stride;
            temp_height--;
            if (temp_height < 0)
                break;
        }
    }
    filled = temp_filled;
    height = temp_height;
    dst = temp_dst;
}
