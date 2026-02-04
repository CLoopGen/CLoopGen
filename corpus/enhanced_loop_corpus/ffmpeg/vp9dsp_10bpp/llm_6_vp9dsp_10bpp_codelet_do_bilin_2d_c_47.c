#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int mx;
extern uint16_t *tmp_ptr;
extern  uint16_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    uint16_t prev_src = src[0];
    uint16_t temp;
    for (i = 0; i < w; i++) {
        temp = src[i + 1] - prev_src;
        tmp_ptr[i] = (prev_src + ((mx * temp + 8) >> 4));
        prev_src = src[i + 1]; 
    }
}
