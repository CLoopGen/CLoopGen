#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t * pixels;
extern  int w;
extern  int linesize;
extern  int row;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_i = 0;
    for (i = 0; i < w; i++) {
        if (pixels[row * linesize + i * 4 + 0] != 0) {
            temp_i = i;
            break;
        }
        temp_i = i + 1;
    }
    i = temp_i;
}
