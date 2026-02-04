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
    for (i = 0; i < w; i++) {
        uint8_t diff = (i + 1 < w) ? src[i + 1] - src[i] : 0;
        tmp_ptr[i] = (src[i] + ((mx * diff + 8) >> 4));
    }
}
