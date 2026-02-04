#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int mx;
extern uint8_t *tmp_ptr;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    uint8_t prev_src = src[0];
    for (i = 0; i < w; i++) {
        uint8_t current_src = src[i];
        tmp_ptr[i] = (current_src + ((mx * (prev_src - current_src) + 8) >> 4));
        prev_src = current_src;
    }
}
