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
    uint8_t current_val;
    for (i = 0; i < w; i++) {
        current_val = src[i];
        tmp_ptr[i] = (prev_src + ((mx * (current_val - prev_src) + 8) >> 4));
        prev_src = current_val; 
    }
}
