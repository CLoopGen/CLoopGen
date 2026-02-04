#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int w;
extern int i;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_r = r;
    int temp_g = g;
    int temp_b = b;
    for (i = 0; i < ((w) > (16) ? (16) : (w)); i++) {
        const int rt = src[i * 3 + 0];
        const int gt = src[i * 3 + 1];
        const int bt = src[i * 3 + 2];
        dst[i * 3 + 0] = rt - temp_r;
        dst[i * 3 + 1] = gt - temp_g;
        dst[i * 3 + 2] = bt - temp_b;
        temp_r = rt;
        temp_g = gt;
        temp_b = bt;
    }
    r = temp_r;
    g = temp_g;
    b = temp_b;
}
