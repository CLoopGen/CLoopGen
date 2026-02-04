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
    int prev_r = r;
    int prev_g = g;
    int prev_b = b;
    for (i = 0; i < ((w) > (16) ? (16) : (w)); i++) {
        const int idx = i * 3;
        const int rt = src[idx + 0];
        const int gt = src[idx + 1];
        const int bt = src[idx + 2];
        const int diff_r = rt - prev_r;
        const int diff_g = gt - prev_g;
        const int diff_b = bt - prev_b;
        dst[idx + 0] = diff_r;
        dst[idx + 1] = diff_g;
        dst[idx + 2] = diff_b;
        prev_r = rt;
        prev_g = gt;
        prev_b = bt;
    }
    r = prev_r;
    g = prev_g;
    b = prev_b;
}
