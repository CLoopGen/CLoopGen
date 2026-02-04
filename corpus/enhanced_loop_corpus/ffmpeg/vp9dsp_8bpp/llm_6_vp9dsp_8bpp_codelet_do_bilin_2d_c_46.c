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
    uint8_t temp;
    for (i = 0; i < w - 1; i++) {
        temp = (src[i] + ((mx * (src[i + 1] - src[i]) + 8) >> 4));
        tmp_ptr[i] = temp;
    }
    if (w > 0) {
        tmp_ptr[w - 1] = src[w - 1]; 
    }
}
