#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;
extern int min_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < min_width; i++) {
        const int rt = src[i * 4 + 2];
        const int gt = src[i * 4 + 1];
        const int bt = src[i * 4 + 0];
        const int at = src[i * 4 + 3];
        dst[i * 4 + 2] = rt - r;
        dst[i * 4 + 1] = gt - g;
        dst[i * 4 + 0] = bt - b;
        dst[i * 4 + 3] = at - a;
        // Introduce artificial WAW and WAR dependencies by reordering updates to r,g,b,a
        // and using temporary variables to break direct flow temporarily.
        int temp_r = rt;
        int temp_g = gt;
        int temp_b = bt;
        int temp_a = at;
        r = temp_r;
        g = temp_g;
        b = temp_b;
        a = temp_a;
    }
}
