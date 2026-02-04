#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int w;
extern int h;
extern int color;
extern int stride;
extern int i;
extern int j;
extern uint16_t *dst2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *temp_row;
    for (j = 0; j < h; j++) {
        temp_row = (uint16_t *)(dst + j * stride);
        for (i = 0; i < w; i++) {
            temp_row[i] = color;
        }
    }
}
