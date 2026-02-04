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
    uint16_t local_accum = 0;
    for (i = 0; i < w; i++) {
        local_accum += src[i]; 
        tmp_ptr[i] = (src[i] + ((mx * (local_accum - src[i]) + 8) >> 4));
    }
}
