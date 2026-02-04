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
    for (i = 0; i < min_width; i += 2) {
        const int rt1 = src[i * 4 + 2];
        const int gt1 = src[i * 4 + 1];
        const int bt1 = src[i * 4 + 0];
        const int at1 = src[i * 4 + 3];
        dst[i * 4 + 2] = rt1 - r;
        dst[i * 4 + 1] = gt1 - g;
        dst[i * 4 + 0] = bt1 - b;
        dst[i * 4 + 3] = at1 - a;

        if (i + 1 < min_width) {
            const int rt2 = src[(i + 1) * 4 + 2];
            const int gt2 = src[(i + 1) * 4 + 1];
            const int bt2 = src[(i + 1) * 4 + 0];
            const int at2 = src[(i + 1) * 4 + 3];
            dst[(i + 1) * 4 + 2] = rt2 - rt1;
            dst[(i + 1) * 4 + 1] = gt2 - gt1;
            dst[(i + 1) * 4 + 0] = bt2 - bt1;
            dst[(i + 1) * 4 + 3] = at2 - at1;
        }

        r = (i + 1 < min_width) ? src[(i + 1) * 4 + 2] : rt1;
        g = (i + 1 < min_width) ? src[(i + 1) * 4 + 1] : gt1;
        b = (i + 1 < min_width) ? src[(i + 1) * 4 + 0] : bt1;
        a = (i + 1 < min_width) ? src[(i + 1) * 4 + 3] : at1;
    }
}
