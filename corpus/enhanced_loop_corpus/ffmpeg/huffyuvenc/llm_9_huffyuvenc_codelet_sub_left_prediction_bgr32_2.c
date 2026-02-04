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
    int factor = (min_width > 16) ? 4 : 2;
    for (i = 0; i < min_width; i++) {
        const int rt = src[i * 4 + 2];
        const int gt = src[i * 4 + 1];
        const int bt = src[i * 4 + 0];
        const int at = src[i * 4 + 3];

        int diff_r = rt - r;
        int diff_g = gt - g;
        int diff_b = bt - b;
        int diff_a = at - a;

        // Increase arithmetic intensity with extra operations
        diff_r = (diff_r * factor) + (diff_r >> 2);
        diff_g = (diff_g * factor) + (diff_g >> 2);
        diff_b = (diff_b * factor) + (diff_b >> 2);
        diff_a = (diff_a * factor) + (diff_a >> 2);

        dst[i * 4 + 2] = diff_r;
        dst[i * 4 + 1] = diff_g;
        dst[i * 4 + 0] = diff_b;
        dst[i * 4 + 3] = diff_a;

        r = rt;
        g = gt;
        b = bt;
        a = at;
    }
}
